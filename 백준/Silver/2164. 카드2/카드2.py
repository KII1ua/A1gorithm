# baekjoon 1920번
import sys
from collections import deque
input = sys.stdin.readline

N = int(input().rstrip())
card = deque(range(1, N+1))

while len(card) > 1:
    card.popleft()          # 제일 위에 있는 카드 버리기
    card.append(card.popleft())     # 위에있는 카드를 뒤로 삽입

print(card[0])