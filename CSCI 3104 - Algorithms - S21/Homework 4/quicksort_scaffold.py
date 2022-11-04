def verifySorted(A):
    for i in range(len(A)-1):
        if A[i] > A[i+1]:
            # print(f"A[{i}]=={A[i]} is greater than A[{i+1}]=={A[i+1]}")
            print("not sorted")
            return
    print("Array is sorted!")


# Input:
#  array A from which to find a pivot
# Return:
#  value of the pivot
def pickPivot(A):
    return(A[-1]) # always use the last value of the array A



# def partitionInPlace(A,p,r):
#     pivotvalue = A[r]
#     i = p-1
#     for j in range(p, r-1): 
#         if A[j] <= pivotvalue: 
#             i = i+1
#             A[i], A[j] = A[j], A[i] 
#     A[i+1], A[r] = A[r], A[i+1] 
#     return (i+1) 


# Input:
#   A is the array to be partitioned
#   pivotvalue is the value around which to pivot (assumes at least one element
#     has value not less than pivotvalue)
# Return:
#   returns an index in A
#   A has been reordered such that every element below the index is less than
#      the pivotvalue, every element above the index is not less than the
#      pivotvalue, and there are no elements in A that are less than the element
#      at the index that are not less than the pivotvalue


def partitionInPlace(A,pivotvalue):
    r = len(A)
    i = 1
    for j in range(1,r):
        if A[j]<pivotvalue:
            A[i], A[j] = A[j], A[i] 
            i +=1
    A[0], A[i-1] = A[i-1], A[0] 
    return i-1 


# Input:
#   an array A to be sorted
# Returns:
#   A has been sorted
def quicksort(A):
    # manual sort for small arrays
    # if len(A) < 3:
    #     if len(A) > 1:
    #         if A[1] < A[0]:
    #             A[0], A[1] = A[1], A[0] 
    #     return A
    if len(A) == 1:
        return A
    # set up recursions
    if len(A) > 1:
        pivotvalue = A[0]
        partitionindex = partitionInPlace(A,pivotvalue)
        quicksort(A[:partitionindex-1])
        quicksort(A[partitionindex+1:])



### Driver
def main():
    # create
    # import numpy.random
    # numpy.random.seed(0)
    # A = numpy.random.randint(0,100,100)
    A = [2,6,3,7]

    # sort
    quicksort(A)

    # verify
    print(A)
    verifySorted(A)
    

if __name__ == "__main__":
    main()









# -----------------------------


# Python program for implementation of Quicksort Sort 

# This function takes last element as pivot, places 
# the pivot element at its correct position in sorted 
# array, and places all smaller (smaller than pivot) 
# to left of pivot and all greater elements to right 
# of pivot 


def partition(arr, low, high): 
	i = (low-1)		 # index of smaller element 
	pivot = arr[high]	 # pivot 

	for j in range(low, high): 

		# If current element is smaller than or 
		# equal to pivot 
		if arr[j] <= pivot: 

			# increment index of smaller element 
			i = i+1
			arr[i], arr[j] = arr[j], arr[i] 

	arr[i+1], arr[high] = arr[high], arr[i+1] 
	return (i+1) 

# The main function that implements QuickSort 
# arr[] --> Array to be sorted, 
# low --> Starting index, 
# high --> Ending index 

# Function to do Quick sort 


# def quickSort(arr, low, high): 
#     if len(arr) == 1: 
#         return arr 
#     if low < high: 

# 		# pi is partitioning index, arr[p] is now 
# 		# at right place 
#         pi = partition(arr, low, high) 

# 		# Separately sort elements before 
# 		# partition and after partition 
#         quickSort(arr, low, pi-1) 
#         quickSort(arr, pi+1, high) 


def quickSort(arr, low, high): 
    if len(arr) == 1: 
        return arr 
    if low < high: 

		# pi is partitioning index, arr[p] is now 
		# at right place 
        pi = partition(arr, low, high) 

		# Separately sort elements before 
		# partition and after partition 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 







# Driver code to test above 
arr = [10, 7, 8, 9, 1, 5, 4, 12] 
n = len(arr) 
quickSort(arr, 0, n-1) 
print("Sorted array is:") 
for i in range(n): 
	print("%d" % arr[i]), 

# This code is contributed by Mohit Kumra 
#This code in improved by https://github.com/anushkrishnav 








# def quicksort(ar):
#     pivot = ar[0]
#     ar[:] = partition(ar[:], pivot)
#     return ""

# def partition(ar, pivot):
#     l = len(ar)
    
#     start_index = 0
#     end_index = l-1
#     new_ar = []
    
#     for i in range(1,l):
#         if ar[i] < pivot:
#             new_ar.append(ar[i])
    
#     l1 = len(new_ar)
#     if l1 > 1:
#         new_ar[:] = partition(new_ar[:], pivot)
        
#     new_ar.append(pivot)
#     for i in range(1,l):
#         if ar[i] >= pivot:
#             new_ar.append(ar[i])
#     l2 = l - l1 - 1
#     if l2 > 1:
#         new_ar[l1+1:] = partition(new_ar[l1+1:], pivot)
#     return new_ar
