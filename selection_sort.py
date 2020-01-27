N = int(input())
A = list(map(int, input().split()))

def selection_sort(A, N):
    count = 0
    for i in range(0, N):
        min_j = i
        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j
        if min_j != i:
            count += 1
        A[i], A[min_j] = A[min_j], A[i]
    return A, count

A, count = selection_sort(A, N)
print(' '.join(map(str, A)))
print(count)