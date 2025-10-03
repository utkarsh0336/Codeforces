/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1'000'000'007;

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    static int dp[305][305], ndp[305][305];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;

    for (int idx = 1; idx <= n; idx++) {
        int v = a[idx];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                ndp[i][j] = 0;

        for (int lastA = 0; lastA <= n; lastA++) {
            for (int lastB = 0; lastB <= n; lastB++) {
                int ways = dp[lastA][lastB];
                if (!ways) continue;

                // option 1: skip
                ndp[lastA][lastB] = (ndp[lastA][lastB] + ways) % MOD;

                // option 2: try greedy placement
                if (lastA == 0 || lastA <= v) {
                    ndp[v][lastB] = (ndp[v][lastB] + ways) % MOD;
                } else if (lastB == 0 || lastB <= v) {
                    ndp[lastA][v] = (ndp[lastA][v] + ways) % MOD;
                }
                // else can't place
            }
        }
        // move to next
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = ndp[i][j];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ans = (ans + dp[i][j]) % MOD;

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
