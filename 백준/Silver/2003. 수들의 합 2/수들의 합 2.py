# baekjoon 19941
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))
count = 0
start = 0
end =  0

while end < N:
    tmp = sum(arr[start:end+1])

    if tmp == M:
        count += 1
        end += 1
    elif tmp > M:
        start += 1
    else:
        end += 1
    
print(count)