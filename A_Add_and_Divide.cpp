/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int a, int b) {
    int ans = LLONG_MAX;
    int add = 0;

    if (b == 1) { // must increase b first
        b++;
        add = 1;
    }

    // Try increasing b up to about 40 steps (enough because a ≤ 1e9 usually)
    for (int i = 0; i <= 40; i++) {
        int x = a, steps = 0;
        while (x > 0) {
            x /= (b + i);
            steps++;
        }
        ans = min(ans, steps + add + i);
    }

    return ans;
}

void Solve() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
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
