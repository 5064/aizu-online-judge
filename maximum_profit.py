N = int(input())
R = [int(input()) for _ in range(N)]

max_profit = float('inf') * -1
min_v = R[0]
for i in range(1, len(R)):
    max_profit = max(max_profit, R[i]-min_v)
    min_v = min(min_v, R[i])

print(max_profit)