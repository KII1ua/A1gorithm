# baekjoon 7662
import sys
import heapq
input = sys.stdin.readline

def isEmpty(nums):
    for item in nums:
        if item[1] > 0:
            return False
    return True

T = int(input())

for _ in range(T):
    min_heap = []
    max_heap = []
    nums = dict()
    a = int(input())

    for j in range(a):
        left, right = input().split()
        num = int(right)

        if left == 'I':
            if num in nums:
                nums[num] += 1
            else:
                nums[num] = 1
                heapq.heappush(min_heap, num)
                heapq.heappush(max_heap, -num)
        elif left == 'D':
            if not isEmpty(nums.items()):
                if num == 1:
                    while -max_heap[0] not in nums or nums[-max_heap[0]] < 1:
                        temp = -heapq.heappop(max_heap)
                        if temp in nums:
                            del(nums[temp])
                    nums[-max_heap[0]] -= 1
                else:
                    while min_heap[0] not in nums or nums[min_heap[0]] < 1:
                        temp = heapq.heappop(min_heap)
                        if temp in nums:
                            del(nums[temp])
                    nums[min_heap[0]] -= 1

    if isEmpty(nums.items()):
        print("EMPTY")
    else:
        while min_heap[0] not in nums or nums[min_heap[0]] < 1:
                heapq.heappop(min_heap)
        while -max_heap[0] not in nums or nums[-max_heap[0]] < 1:
            heapq.heappop(max_heap)
        print(-max_heap[0], min_heap[0])