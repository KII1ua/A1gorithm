# baekjoon 1302
import sys
input = sys.stdin.readline

N = int(input())
result = {}

for i in range(N):
    a = input().rstrip()

    if a not in result:
        result[a] = 1
    else:
        result[a] += 1

        
tmp = [k for k,v in result.items() if max(result.values()) == v]

tmp.sort()
print("{}".format(tmp[0]))