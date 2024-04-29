from heapq import heapify, heappop,  heappush
import sys
n = int(input())
arr = list(map(int, sys.stdin.readline().split()))
q = []
heapify(q)

curr = 0
res = 0
for i in arr:
    heappush(q, i)
    curr += i
    while curr < 0 and len(q):
        x = heappop(q)
        curr -= 2*x
        res += 1

print(res)