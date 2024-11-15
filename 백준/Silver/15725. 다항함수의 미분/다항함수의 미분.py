#baekjoon 15725
import sys
input = sys.stdin.readline

a = input().rstrip()
result = ""

if 'x' not in a:
    print(0)
else:
    for i in a:
        if i == "x":
            if result == "-":
                print(-1)
            elif result == "":
                print(1)
            else:
                print(result)
        else:
            result += i