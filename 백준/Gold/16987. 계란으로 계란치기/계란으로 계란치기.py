import sys
input = sys.stdin.readline

lst = []
N = int(input())
answer = 0

def func(x):
    global answer
    if(x == N):
        cnt = 0
        for i in range(N):
            if(lst[i][0] <= 0):
                cnt += 1
        answer = max(answer, cnt)
        return

    for i in range(N):
        if lst[x][0] <= 0: func(x+1)
        elif i == x or lst[i][0] <= 0:
            continue
        else:
            lst[x][0] -= lst[i][1]
            lst[i][0] -= lst[x][1]
            func(x+1)
            lst[x][0] += lst[i][1]
            lst[i][0] += lst[x][1]
    
    count = 0
    for i in range(N):
        if(lst[i][0] <= 0): count += 1
    
    answer = max(answer, count)

for i in range(N):
    a, b = map(int, input().split())
    lst.append([a, b])

func(0)

print(answer)