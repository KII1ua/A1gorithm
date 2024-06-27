# baekjoon 2798
import sys
input = sys.stdin.readline

def dfs(start, depth, current_sum):
    global max_sum 

    if depth == 3:
        if current_sum <= M and current_sum > max_sum:
            max_sum = current_sum
        return
    
    for i in range(start, N):
        if current_sum + card[i] > M:
            continue
        dfs(i + 1, depth + 1, current_sum + card[i])

N, M = list(map(int, input().split()))
card = list(map(int, input().split()))
max_sum = 0

dfs(0,0,0)
print(max_sum)