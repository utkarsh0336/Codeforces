#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    unordered_map<long long, long long> mpa, mpb;

    for (auto na : a) mpa[na]++;
    for (auto nb : b) mpb[nb]++;

    long long ans = 0;
    for (auto &it : mpa) {
        if (mpb.find(it.first) != mpb.end()) {
            ans += mpa[it.first] * mpb[it.first];
        }
    }

    cout << ans << "\n";
    return 0;
}
