def insertion_sort(A, n, g):
    count = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j= j - g
            count += 1
        A[j+g] = v
    return count


def shell_sort(A, n):
    count = 0
    m = 
    G[] = {}
    for i in range(0, m):
        insertion_sort(A, n, G[i])


if __name__ == "__main__":
    N = int(input())