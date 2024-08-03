# baekjoon 28702
import sys
input = sys.stdin.readline

for _ in range(3, 0, -1):
    i = input().rstrip()
    if i not in ['Fizz', 'Buzz', 'FizzBuzz']:
        a = int(i) + _

if a % 3 == 0 and not a % 5 == 0:
    print("Fizz")
elif a % 5 == 0 and not a % 3 == 0:
    print("Buzz")
elif a % 5 == 0 and a % 3 == 0:
    print("FizzBuzz")
else:
    print(a)