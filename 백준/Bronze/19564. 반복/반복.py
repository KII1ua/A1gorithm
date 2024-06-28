# baekjoon 1920번
import sys
input = sys.stdin.readline

alpha = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13,
         'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
result = []
min = 1

S = input().rstrip()

for i in list(S):
    result.append(alpha[i])

for _ in range(len(result) - 1):
    if result[_] >= result[_+1]:
        min += 1
    else:
        continue

if len(result) == 0:
    print('0')
    sys.exit()

print(min)