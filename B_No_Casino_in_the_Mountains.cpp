/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int i = 0;
    while (i <= n - k) {
        bool good = true;
        for (int j = 0; j < k; j++) {
            if (a[i + j] == 1) {
                good = false;
                break;
            }
        }
        if (good) {
            ans++;
            i += k + 1; // k hiking days + 1 break day
        } else {
            i++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
