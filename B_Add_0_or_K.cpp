#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool allEven = true;
        for (int x : a) {
            if (x % 2 == 1) {
                allEven = false;
                break;
            }
        }

        if (allEven) {
            for (int i = 0; i < n; i++) 
                cout << a[i] << (i + 1 == n ? '\n' : ' ');
            continue;
        }

        if (k % 2 == 1) {
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 1) a[i] += k;
            }
        } else {
            for (int i = 0; i < n; i++) {
                a[i] += k;
            }
        }

        for (int i = 0; i < n; i++) 
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
