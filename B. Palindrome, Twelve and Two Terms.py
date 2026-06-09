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
    def isPalindrome(s):
        l , r = 0 , len(s) - 1
        while l <= r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True


    n = int(input())
    
    
    b = n - (n % 12)
    numa = n - b
    a = str(numa)

    while not isPalindrome(str(a)):
        b -= 12
        numa += 12
        a = str(numa)
    
    if int(a) < 0 or b < 0:
        print(-1)
        return
    print(int(a),end=" ")
    print(b)

def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()