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
    n = int(input())
    a = list(map(int, input().split()))

    cnt = 1 if a[-1] > 0 else 0
    best_sum = a[-1]

    for i in range(n - 2, -1, -1):
        # Option 1: keep a[i] separate
        split_cnt = cnt + (1 if a[i] > 0 else 0)
        split_sum = a[i]

        # Option 2: merge a[i] with the block on the right
        merge_sum = a[i] + best_sum
        merge_cnt = cnt + (1 if merge_sum > 0 else 0)

        # Choose the better option
        if merge_cnt > split_cnt:
            cnt = merge_cnt
            best_sum = merge_sum
        elif split_cnt > merge_cnt:
            cnt = split_cnt
            best_sum = split_sum
        else:
            # If both give same positives, keep larger sum for future left side
            cnt = split_cnt
            best_sum = max(split_sum, merge_sum)

    print(cnt)

        
def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()