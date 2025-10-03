/*Utkarsh Sahay*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1001, M = 10, MOD = 1e9 + 7;
int n, m, dp[M][N][N];

int f(int index, int aNum, int bNum) {
    if (index == m) return 1;

    if (aNum > bNum || bNum < 1 || aNum > n) return 0;

    if (dp[index][aNum][bNum] != -1) return dp[index][aNum][bNum];

    return dp[index][aNum][bNum] = (
        f(index + 1, aNum, bNum)
        + f(index, aNum + 1, bNum)
        + f(index, aNum, bNum - 1)
        - f(index, aNum + 1, bNum - 1) + MOD
    ) % MOD;
}

int32_t main() {

    
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 1, n) << "\n";

    return 0;
}
