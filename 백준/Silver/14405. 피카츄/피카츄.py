# baekjoon 14405
import sys
input = sys.stdin.readline
S = input().rstrip()

S = S.replace('pi', ' ')
S = S.replace('ka', ' ')
S = S.replace('chu', ' ')

if len(S.strip()) == 0:
    print("YES")
else:
    print("NO")