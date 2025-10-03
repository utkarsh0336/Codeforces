// Utkarsh Sahay - solution
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        vector<ll> prefA(n + 1), prefB(m + 1);
        for (int i = 1; i <= n; i++) prefA[i] = prefA[i - 1] + a[i - 1];
        for (int i = 1; i <= m; i++) prefB[i] = prefB[i - 1] + b[i - 1];
        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;
            int tmin = max(0, z - min(y, m));
            int tmax = min({n, x, z});
            if (tmin > tmax) {
                cout << 0 << "\n";
                continue;
            }
            auto f = [&](int tval) {
                int u = z - tval;
                if (u < 0 || u > m || u > y) return -1LL;
                return prefA[tval] + prefB[u];
            };
            int l = tmin, r = tmax;
            ll best = 0;
            while (r - l > 3) {
                int m1 = l + (r - l) / 3;
                int m2 = r - (r - l) / 3;
                if (f(m1) < f(m2)) l = m1;
                else r = m2;
            }
            for (int tval = l; tval <= r; tval++) best = max(best, f(tval));
            cout << best << "\n";
        }
    }
}
