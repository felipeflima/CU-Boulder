/* 
 * mm-implicit.c -  Simple allocator based on implicit free lists, 
 *                  first fit placement, and boundary tag coalescing. 
 *
 * Each block has header and footer of the form:
 * 
 *      31                     3  2  1  0 
 *      -----------------------------------
 *     | s  s  s  s  ... s  s  s  0  0  a/f
 *      ----------------------------------- 
 * 
 * where s are the meaningful size bits and a/f is set 
 * iff the block is allocated. The list has the following form:
 *
 * begin                                                          end
 * heap                                                           heap  
 *  -----------------------------------------------------------------   
 * |  pad   | hdr(8:a) | ftr(8:a) | zero or more usr blks | hdr(8:a) |
 *  -----------------------------------------------------------------
 *          |       prologue      |                       | epilogue |
 *          |         block       |                       | block    |
 *
 * The allocated prologue and epilogue blocks are overhead that
 * eliminate edge conditions during coalescing.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
  /* Team name */
  "Brazilian Team",
  /* First member's full name */
  "Felipe Lima",
  /* First member's email address */
  "felipe.lima@colorado.edu",
  /* Second member's full name (leave blank if none) */
  "Lucas Gama",
  /* Second member's email address (leave blank if none) */
  "lucas.gama@colorado.edu"
};

/////////////////////////////////////////////////////////////////////////////
// Constants and macros
//
// These correspond to the material in Figure 9.43 of the text
// The macros have been turned into C++ inline functions to
// make debugging code easier.
//
/////////////////////////////////////////////////////////////////////////////
/* some of the code was adapted from 
http://csapp.cs.cmu.edu/3e/ics3/code/vm/malloc/mm.c 
and 
http://www.cs.cmu.edu/~410-f11/update/proj3/410user/libmalloc/mm_malloc.c 
*/

#define WSIZE       4       /* word size (bytes) */  
#define DSIZE       8       /* doubleword size (bytes) */
#define CHUNKSIZE  (1<<12)  /* initial heap size (bytes) */
#define OVERHEAD    8       /* overhead of header and footer (bytes) */
#define ALIGNMENT   8 
#define HEAP_SIZE  24      /*Initial size for heap(including padding, prolouge header and footer, epilouge header as well as back_link and forward_link (for free list)) (6 * 4bytes)*/

static inline int MAX(int x, int y) {
  return x > y ? x : y;
}

//
// Pack a size and allocated bit into a word
// We mask of the "alloc" field to insure only
// the lower bit is used
//
static inline uint32_t PACK(uint32_t size, int alloc) {
  return ((size) | (alloc & 0x1));
}

//
// Read and write a word at address p
//
static inline uint32_t GET(void *p) { return  *(uint32_t *)p; }
static inline void PUT( void *p, uint32_t val)
{
  *((uint32_t *)p) = val;
}

//
// Read the size and allocated fields from address p
//
static inline uint32_t GET_SIZE( void *p )  { 
  return GET(p) & ~0x7;
}

static inline int GET_ALLOC( void *p  ) {
  return GET(p) & 0x1;
}

//
// Given block ptr bp, compute address of its header and footer
//
static inline void *HDRP(void *bp) {

  return ( (char *)bp) - WSIZE;
}
static inline void *FTRP(void *bp) {
  return ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE);
}

//
// Given block ptr bp, compute address of next and previous blocks
//
static inline void *NEXT_BLKP(void *bp) {
  return  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)));
}

static inline void* PREV_BLKP(void *bp){
  return  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)));
}

#define SUCC(bp)     (*(void **)(bp))
#define FORWARD(bp)  (*(void **)(bp + ALIGNMENT)) 
#define ALIGN(p) (((size_t)(p) + (ALIGNMENT -1)) & ~0x7)
#define PRED(bp)  (*(void **)(bp + ALIGNMENT)) 
#define BACK(bp) (*(void **)(bp))


/////////////////////////////////////////////////////////////////////////////
//
// Global Variables
//

static char *heap_listp;  /* pointer to first block */  
void *list_root;

//
// function prototypes for internal helper routines
//
static void *extend_heap(uint32_t words);
static void place(void *bp, uint32_t asize);
static void *find_fit(uint32_t asize);
static void *coalesce(void *bp);
// static void printblock(void *bp); 
// static void checkblock(void *bp);
static void heapPut(void *bp, size_t size, int bool);
static void nodeNew(void *bp);
static void nodeDel(void *bp);




//
// mm_init - Initialize the memory manager 
//
int mm_init(void) 
{
  if ((heap_listp = mem_sbrk(2*HEAP_SIZE)) == NULL)
  {
       return -1;
  }
    PUT(heap_listp, 0);                     
    PUT(heap_listp+WSIZE, PACK(HEAP_SIZE, 1));  
    PUT(heap_listp+HEAP_SIZE, PACK(HEAP_SIZE, 1));     
    PUT(heap_listp+WSIZE+(HEAP_SIZE), PACK(0, 1));   
    heap_listp += DSIZE;    
    
    PUT(heap_listp+DSIZE, 0); 
    PUT(heap_listp+DSIZE+WSIZE, 0); 

    list_root = heap_listp;

    if (extend_heap(CHUNKSIZE/DSIZE) == NULL)
    {
        return -1;
    }
    return 0;
}


//
// extend_heap - Extend heap with free block and return its block pointer
//
static void *extend_heap(uint32_t words) 
{
    char *bp;
    size_t size;
        
    size = (words % 2) ? (words+1) * WSIZE : words * WSIZE;
    if ((bp = mem_sbrk(size)) == (void *)-1) 
    {
         return NULL;
    }

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); 

    return coalesce(bp);
}

//
// Practice problem 9.8
//
// find_fit - Find a fit for a block with asize bytes 
//
static void *find_fit(uint32_t asize)
{
    void *bp;

    for (bp = list_root; GET_ALLOC(HDRP(bp)) == 0; bp = PRED(bp))
    {
        if (GET_SIZE(HDRP(bp)) >= asize)
        {
            return bp;
        }
    }
    return NULL; /* no fit */
}

// 
// mm_free - Free a block 
//
void mm_free(void *bp)
{
    size_t size = GET_SIZE(HDRP(bp));   
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    coalesce(bp);
}

//
// coalesce - boundary tag coalescing. Return ptr to coalesced block
//
static void *coalesce(void *bp) 
{
  void *prevBlock = PREV_BLKP(bp);
  size_t prev_alloc = 0;
  
  if(GET_ALLOC(FTRP(prevBlock)) || prevBlock == bp)
  {
    prev_alloc = 1;
  }
  
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size = GET_SIZE(HDRP(bp));
  int flag = 0; 
  
  if (prev_alloc && !next_alloc)
  {
      size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
      nodeDel(NEXT_BLKP(bp));
      PUT(HDRP(bp), PACK(size, 0));
      PUT(FTRP(bp), PACK(size, 0));
  }

  else if (!prev_alloc && next_alloc)          
  {
      flag = 1;
      size += GET_SIZE(HDRP(PREV_BLKP(bp)));
      PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
      PUT(FTRP(PREV_BLKP(bp)), PACK(size, 0));
      nodeDel(PREV_BLKP(bp));
  }

  else if (!prev_alloc && !next_alloc)         
  {
      flag = 1;
      size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(HDRP(NEXT_BLKP(bp)));
      nodeDel(PREV_BLKP(bp));
      nodeDel(NEXT_BLKP(bp));
      PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
      PUT(FTRP(PREV_BLKP(bp)), PACK(size, 0));
  }
  if(flag)
  { 
    bp = PREV_BLKP(bp);
    nodeNew(bp);
    return bp;
  }
  nodeNew(bp);
  return bp;
}

//
// mm_malloc - Allocate a block with at least size bytes of payload 
//
void *mm_malloc(uint32_t size) 
{
  size_t asize;     
    size_t extendsize; 
    char *bp;      

    
    if (size <= 0)
    {
        return NULL;
    }

    if((ALIGN(size) + DSIZE) < HEAP_SIZE)
    {
        asize = HEAP_SIZE;
    }
    else
    {
        asize = ALIGN(size) + DSIZE;
    }

    if ((bp = find_fit(asize)) != NULL) {
        place(bp, asize);
        return bp;
    }

    extendsize = MAX(asize,CHUNKSIZE);
    if ((bp = extend_heap(extendsize/WSIZE)) == NULL)
    {
        return NULL;
    }
    place(bp, asize);
    return bp;
} 

//
//
// Practice problem 9.9
//
// place - Place block of asize bytes at start of free block bp 
//         and split if remainder would be at least minimum block size
//
static void place(void *bp, uint32_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));   

    if ((csize - asize) >= (HEAP_SIZE))
    { 
        PUT(HDRP(bp), PACK(asize, 1));
        PUT(FTRP(bp), PACK(asize, 1));
        nodeDel(bp);
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(csize-asize, 0));
        PUT(FTRP(bp), PACK(csize-asize, 0));
       	coalesce(bp);
    }
    else 
    { 
      PUT(HDRP(bp), PACK(csize, 1));
      PUT(FTRP(bp), PACK(csize, 1));
      nodeDel(bp);
    }

}


//
// mm_realloc 
//
void *mm_realloc(void *bp, uint32_t size)
{     
    
  if (bp == NULL) 
  {
      mm_malloc(size);
      return NULL;
  }  
  if((int)size == 0)
  { 
    mm_free(bp); 
    return NULL; 
  } 
  else if(size > 0)
  { 
      size_t oldsize = GET_SIZE(HDRP(bp)); 
      size_t newsize = size + HEAP_SIZE; 
      if(newsize <= oldsize)
      { 
          return bp; 
      }
      else 
      { 
          size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp))); 
          size_t csize;
         
          if(!next_alloc && ((csize = oldsize + GET_SIZE(HDRP(NEXT_BLKP(bp))))) >= newsize)
          { 
            nodeDel(NEXT_BLKP(bp));
            heapPut(bp, csize, 1); 
            return bp; 
          }
          else
          {  
            void *new_ptr = mm_malloc(newsize);  
            place(new_ptr, newsize);
            memcpy(new_ptr, bp, newsize); 
            mm_free(bp); 
            return new_ptr; 
          } 
      }
  } else {
    return NULL;
  }
}

// void mm_checkheap(int verbose) 
// {
//   //
//   // This provided implementation assumes you're using the structure
//   // of the sample solution in the text. If not, omit this code
//   // and provide your own mm_checkheap
//   //
//   void *bp = heap_listp;
  
//   if (verbose) {
//     printf("Heap (%p):\n", heap_listp);
//   }

//   if ((GET_SIZE(HDRP(heap_listp)) != DSIZE) || !GET_ALLOC(HDRP(heap_listp))) {
// 	printf("Bad prologue header\n");
//   }
//   checkblock(heap_listp);

//   for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
//     if (verbose)  {
//       printblock(bp);
//     }
//     checkblock(bp);
//   }
     
//   if (verbose) {
//     printblock(bp);
//   }

//   if ((GET_SIZE(HDRP(bp)) != 0) || !(GET_ALLOC(HDRP(bp)))) {
//     printf("Bad epilogue header\n");
//   }
// }

// static void printblock(void *bp) 
// {
//   uint32_t hsize, halloc, fsize, falloc;

//   hsize = GET_SIZE(HDRP(bp));
//   halloc = GET_ALLOC(HDRP(bp));  
//   fsize = GET_SIZE(FTRP(bp));
//   falloc = GET_ALLOC(FTRP(bp));  
    
//   if (hsize == 0) {
//     printf("%p: EOL\n", bp);
//     return;
//   }

//   printf("%p: header: [%d:%c] footer: [%d:%c]\n",
// 	 bp, 
// 	 (int) hsize, (halloc ? 'a' : 'f'), 
// 	 (int) fsize, (falloc ? 'a' : 'f')); 
// }

// static void checkblock(void *bp) 
// {
//   if ((uintptr_t)bp % 8) {
//     printf("Error: %p is not doubleword aligned\n", bp);
//   }
//   if (GET(HDRP(bp)) != GET(FTRP(bp))) {
//     printf("Error: header does not match footer\n");
//   }
// }



static void heapPut(void *bp, size_t size, int bool){
  PUT(HDRP(bp), PACK(size, bool));
  PUT(FTRP(bp), PACK(size, bool));
}


static void nodeNew(void *bp){
    void *head = (void*)list_root;
    if(list_root == NULL)
    {
        list_root = bp;
        BACK(bp) = NULL;
        FORWARD(bp) = NULL;   
    } 
    else 
    {
        FORWARD(bp) = head;
        BACK(bp) = NULL;
        BACK(head) = bp;
        list_root = bp;
    }
}


static void nodeDel(void *bp){
    void *temp_back = BACK(bp);
    void *temp_forward = FORWARD(bp);
    
    if(BACK(bp) == NULL)
    {
        list_root = FORWARD(bp);
        if(temp_forward != NULL)
        {
            BACK(temp_forward) = BACK(bp);
        }
    } 
    else 
    { 
        FORWARD(temp_back) = FORWARD(bp);
        if (temp_forward != NULL){
            BACK(temp_forward) = BACK(bp);
        }
    }
    bp = NULL; 
}