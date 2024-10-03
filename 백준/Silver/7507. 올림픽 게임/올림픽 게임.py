#baekjoon 7507
import sys
input = sys.stdin.readline

N = int(input())

for _ in range(1, N+1):
    arr = []
    m = int(input())
    for i in range(m):
        i = list(map(int, input().split()))
        arr.append(i)
    arr.sort(key = lambda x : (x[0], x[2]))
    res = 1
    day, start, end = arr[0]
    for i in range(1, m):
        if day != arr[i][0] or end <= arr[i][1]:
            day, start, end = arr[i]
            res += 1
    
    print("Scenario #{}:".format(_))
    print(res)
    print()