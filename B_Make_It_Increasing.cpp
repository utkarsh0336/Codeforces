#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        while (a[i] >= a[i + 1]) {
            if (a[i] == 0) {
                cout << -1 << "\n";
                return;
            }
            a[i] /= 2;
            ans++;
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
