#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    while (true) {
        bool dec = false;

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                a[i]--;
                dec = true;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                a[i]++;
                break; 
            }
        }

        ans++;

        if (!dec) break;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
