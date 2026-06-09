# Utkarsh Sahay

import sys
import math
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from functools import lru_cache
from itertools import permutations, combinations, accumulate

# Fast input
input = sys.stdin.readline

# Large values
INF = 10**18
MOD = 10**9 + 7

# Recursion limit
sys.setrecursionlimit(2 * 10**5)


def solve():
    # your logic here
    n = int(input())
    a = list(map(int, input().split()))

    a.sort(reverse=True)
    invalid = False

    # if len(a) <= 2:
    #     print(a[:2])
    #     return

    for i in range(2,len(a)):
        if a[i] != a[i-2] % a[i-1]:
            invalid = True
            break
        
    if invalid:
        print(-1)
    else:
        print(a[0],end=" ")
        print(a[1])


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()