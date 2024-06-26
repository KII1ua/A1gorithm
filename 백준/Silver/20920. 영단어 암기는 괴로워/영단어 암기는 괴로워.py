import sys
input = sys.stdin.readline

N, M = map(int, input().split())
word = {}

for _ in range(N):
    w = input().rstrip()
    if len(w) >= M:
        word[w] = word.get(w, 0) + 1

sorted_words = sorted(word.items(), key=lambda x: (-x[1], -len(x[0]), x[0]))

for w, _ in sorted_words:
    print(w)