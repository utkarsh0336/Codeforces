import sys

input = sys.stdin.readline

def solve():
    n = int(input())
    ans = list(range(n + 1, 2 * n + 1))
    print(*ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()