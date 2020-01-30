import copy

def bubble_sort(C, N):
    for i in range(N):
        for j in range(N-1, i, -1):
            if C[j]['value'] < C[j-1]['value']:
                C[j], C[j-1] = C[j-1], C[j]


def selection_sort(C, N):
    for i in range(N):
        min_j = i
        for j in range(i, N):
            if C[j]['value'] < C[min_j]['value']:
                min_j = j
        C[i], C[min_j] = C[min_j], C[i]


if __name__ == "__main__":
    N = int(input())
    C = list(map(lambda c: {'suit': c[0:1],'value': int(c[-1])}, input().split()))
    C2 = copy.deepcopy(C)
    bubble_sort(C, N)
    print(' '.join(map(lambda x: x['suit']+str(x['value']), C)))
    print('Stable')  # bubblesort is definitely Stable sort

    selection_sort(C2, N)
    print(' '.join(map(lambda x: x['suit']+str(x['value']), C2)))
    for bc, sc in zip(C, C2):
        if bc['suit'] != sc['suit']:
            print('Not stable')
            exit()
    print('Stable')
