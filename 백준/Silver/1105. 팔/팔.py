# baekjoon 1105
import sys
input = sys.stdin.readline

L, R = input().rstrip().split()
cnt = 0

if len(L) != len(R):
    print(0)
    sys.exit()
else:
    for i in range(len(L)):
        if L[i] == R[i]:
            if L[i] == '8':
                cnt += 1
        else:
            break
    print(cnt)