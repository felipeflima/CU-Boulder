def partitionInPlace(A,pivotvalue):
    high = len(A)
    i = 1
    for j in range(1,high):
        if A[j]<pivotvalue:
            A[i], A[j] = A[j], A[i] 
            i +=1
    A[0], A[i-1] = A[i-1], A[0] 
    return i-1

def quicksort(A):
    n = len(A)
    if n == 1:
        return A,0

    if len(A) < 3: 
        if (len(A) > 0):
            if A[0] > A[1]:
                A[0], A[1] = A[1], A[0]
            return A,0
    if n>1:
        pivot = A[0]
        pivot_position = partitionInPlace(A,pivot)
        A[:pivot_position],left = quicksort(A[:pivot_position])
        A[pivot_position+1:],right = quicksort(A[pivot_position+1:])
        
        return A,left+right+n-1
    else:
        return A,0

