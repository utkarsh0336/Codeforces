// Utkarsh Sahay - Solution
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    const ull BR = 91138233ULL;
    const ull BC = 97266353ULL;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<string> ar(n, string(m, ' '));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ar[n - 1 - i][m - 1 - j] = a[i][j];

        vector<ull> powR(n + 1), powC(m + 1);
        powR[0] = 1;
        for (int i = 1; i <= n; ++i) powR[i] = powR[i - 1] * BR;
        powC[0] = 1;
        for (int j = 1; j <= m; ++j) powC[j] = powC[j - 1] * BC;

        vector<vector<ull>> H(n + 1, vector<ull>(m + 1, 0));
        vector<vector<ull>> HR(n + 1, vector<ull>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ull v = (ull)(a[i - 1][j - 1]);
                H[i][j] = H[i - 1][j] * BR + H[i][j - 1] * BC - H[i - 1][j - 1] * BR * BC + v;
                ull vr = (ull)(ar[i - 1][j - 1]);
                HR[i][j] = HR[i - 1][j] * BR + HR[i][j - 1] * BC - HR[i - 1][j - 1] * BR * BC + vr;
            }
        }

        auto getHash = [&](const vector<vector<ull>> &P, int r1, int c1, int r2, int c2) -> ull {
            if (r1 > r2 || c1 > c2) return 0ULL;
            ull A = P[r2][c2];
            ull B = P[r1 - 1][c2] * powR[r2 - r1 + 1];
            ull C = P[r2][c1 - 1] * powC[c2 - c1 + 1];
            ull D = P[r1 - 1][c1 - 1] * powR[r2 - r1 + 1] * powC[c2 - c1 + 1];
            return A - B - C + D;
        };

        long long bestAdd = LLONG_MAX;

        for (int s = -(n - 1); s <= n - 1; ++s) {
            int r1 = max(1, 1 + s);
            int r2 = min(n, n + s);
            if (r1 > r2) continue;
            for (int t = -(m - 1); t <= m - 1; ++t) {
                int c1 = max(1, 1 + t);
                int c2 = min(m, m + t);
                if (c1 > c2) continue;

                ull h1 = getHash(H, r1, c1, r2, c2);
                int rr1 = r1 - s, rr2 = r2 - s;
                int cc1 = c1 - t, cc2 = c2 - t;
                ull h2 = getHash(HR, rr1, cc1, rr2, cc2);
                if (h1 != h2) continue;

                int p = s + n + 1;
                int q = t + m + 1;
                int Lr = max({n, p - 1, 2 * n - p + 1});
                if (((Lr - (p - 1)) & 1) != 0) Lr++;
                int Lc = max({m, q - 1, 2 * m - q + 1});
                if (((Lc - (q - 1)) & 1) != 0) Lc++;
                long long N = Lr;
                long long M = Lc;
                long long added = N * M - 1LL * n * m;
                if (added < bestAdd) bestAdd = added;
            }
        }

        if (bestAdd == LLONG_MAX) cout << -1 << '\n';
        else cout << bestAdd << '\n';
    }
    return 0;
}
