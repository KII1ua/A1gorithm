#baekjoon 1874
import sys
input = sys.stdin.readline

n = int(input())
stack = []
result = []
cnt = 1

for i in range(n):
    tmp = int(input())
    while cnt <= tmp:
        stack.append(cnt)
        result.append('+')
        cnt += 1
    
    if stack[-1] == tmp:
        stack.pop()
        result.append('-')
    else:
        print("NO")
        sys.exit()

for i in result:
    print(i)