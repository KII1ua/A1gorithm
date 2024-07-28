import sys
input = sys.stdin.readline

S, C = map(int, input().split())
onion = [int(input()) for x in range(S)]

start = 1
end = max(onion)
rst = 0

while start <= end:
    mid = (start + end) // 2
    cnt = 0

    for i in onion:
        cnt += i // mid
    
    if cnt >= C:
        rst = max(rst, mid)
        start = mid + 1
    else:
        end = mid - 1

result = sum(onion) - (C * rst)
print(result)