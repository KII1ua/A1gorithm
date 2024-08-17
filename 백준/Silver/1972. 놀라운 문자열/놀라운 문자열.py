#baekjoon 1972
import sys
input = sys.stdin.readline

while True:
    X = input().rstrip()

    if X == '*':
        break

    for i in range(1, len(X)-1):
        result = {}
        for j in range(len(X) - i):
            a = X[j] + X[j+i]
            if a not in result:
                result[a] = 1
            else:
                print(X, "is NOT surprising.")
                break
        else:
            continue
        break
    else:
        print(X, "is surprising.")