#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1'000'000'007;

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // The key insight: we need to track the last elements of both sequences
    // But we need to be careful about the initialization and transitions
    
    static int dp[305][305], ndp[305][305];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for (int idx = 1; idx <= n; idx++) {
        int v = a[idx];
        memset(ndp, 0, sizeof(ndp));
        
        for (int lastA = 0; lastA <= n; lastA++) {
            for (int lastB = 0; lastB <= n; lastB++) {
                if (!dp[lastA][lastB]) continue;
                
                // Option 1: skip current element
                ndp[lastA][lastB] = (ndp[lastA][lastB] + dp[lastA][lastB]) % MOD;
                
                // Option 2: add to sequence A (if valid)
                if (lastA == 0 || v >= lastA) {
                    ndp[v][lastB] = (ndp[v][lastB] + dp[lastA][lastB]) % MOD;
                }
                // Option 3: add to sequence B (if valid)
                else if (lastB == 0 || v >= lastB) {
                    ndp[lastA][v] = (ndp[lastA][v] + dp[lastA][lastB]) % MOD;
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans = (ans + dp[i][j]) % MOD;
        }
    }
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
