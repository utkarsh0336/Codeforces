#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve_one(const vector<ll>& a) {
    int n = (int)a.size();

    // initial alternating sum S0
    ll S0 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) S0 += a[i]; // 0-based even = 1-based odd
        else S0 -= a[i];
    }

    // same-parity max distance
    ll best_same = 0;
    if (n >= 2) {
        int min_odd = INT_MAX, max_odd = INT_MIN;
        int min_even = INT_MAX, max_even = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // 0-based even
                min_odd = min(min_odd, i);
                max_odd = max(max_odd, i);
            } else {
                min_even = min(min_even, i);
                max_even = max(max_even, i);
            }
        }
        if (min_odd != INT_MAX) best_same = max(best_same, (ll)(max_odd - min_odd));
        if (min_even != INT_MAX) best_same = max(best_same, (ll)(max_even - min_even));
    }

    // opposite-parity best gain
    const ll INF = (ll)4e18;
    ll min_pref_par0 = INF; // min(2*a[i] + i) for i%2==0
    ll min_pref_par1 = INF; // min(-2*a[i] + i) for i%2==1
    ll bestG = LLONG_MIN;

    for (int j = 0; j < n; j++) {
        if (j % 2 == 1) {
            // j odd (0-based) => 1-based even, pair with i%2==0
            if (min_pref_par0 != INF) {
                ll G = (2 * a[j] + j) - min_pref_par0;
                bestG = max(bestG, G);
            }
        } else {
            // j even (0-based) => 1-based odd, pair with i%2==1
            if (min_pref_par1 != INF) {
                ll G = (-2 * a[j] + j) - min_pref_par1;
                bestG = max(bestG, G);
            }
        }

        // update prefixes
        if (j % 2 == 0) {
            min_pref_par0 = min(min_pref_par0, 2 * a[j] + j);
        } else {
            min_pref_par1 = min(min_pref_par1, -2 * a[j] + j);
        }
    }

    ll best_opposite = (bestG == LLONG_MIN ? LLONG_MIN : bestG);
    ll best_gain = max({0LL, best_same, (best_opposite == LLONG_MIN ? LLONG_MIN : best_opposite)});
    return S0 + best_gain;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve_one(a) << "\n";
    }
    return 0;
}
