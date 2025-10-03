/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;

ll modPow(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll modInv(ll x, ll mod) {
    // mod is prime => inverse = x^(mod-2) % mod
    return modPow(x, mod - 2, mod);
}

void Solve() {
    string s;
    if (!(cin >> s)) return;
    int n = (int)s.size();
    if (n == 0) return;

    const ll p1 = 31;
    const ll p2 = 37;

    // Precompute powers and inverse powers
    vector<ll> pow1(n), pow2(n), invPow1(n), invPow2(n);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < n; ++i) {
        pow1[i] = (pow1[i-1] * p1) % MOD1;
        pow2[i] = (pow2[i-1] * p2) % MOD2;
    }
    for (int i = 0; i < n; ++i) {
        invPow1[i] = modInv(pow1[i], MOD1);
        invPow2[i] = modInv(pow2[i], MOD2);
    }

    // Prefix hashes: h[i] is hash of s[0..i] where character s[i] is multiplied by pow[i]
    vector<ll> h1(n), h2(n);
    h1[0] = ((s[0] - 'a' + 1) * pow1[0]) % MOD1;
    h2[0] = ((s[0] - 'a' + 1) * pow2[0]) % MOD2;
    for (int i = 1; i < n; ++i) {
        ll val1 = ((s[i] - 'a' + 1) * pow1[i]) % MOD1;
        ll val2 = ((s[i] - 'a' + 1) * pow2[i]) % MOD2;
        h1[i] = (h1[i-1] + val1) % MOD1;
        h2[i] = (h2[i-1] + val2) % MOD2;
    }

    // For each possible length len (prefix length = len), compare prefix s[0..len-1]
    // with suffix s[n-len..n-1]
    bool firstPrinted = false;
    for (int len = 1; len < n; ++len) {
        // prefix hash (already normalized starting at position 0)
        ll h1pre = h1[len - 1]; // corresponds to sum_{i=0..len-1} val_i * pow[i]
        ll h2pre = h2[len - 1];

        // raw suffix segment hash: s[n-len .. n-1]
        int start = n - len;
        ll raw1 = h1[n - 1];
        if (start - 1 >= 0) raw1 = (raw1 - h1[start - 1]) % MOD1;
        raw1 = (raw1 + MOD1) % MOD1;

        ll raw2 = h2[n - 1];
        if (start - 1 >= 0) raw2 = (raw2 - h2[start - 1]) % MOD2;
        raw2 = (raw2 + MOD2) % MOD2;

        // normalize suffix to start at power 0 by multiplying with inverse of pow[start]
        ll h1suf = (raw1 * invPow1[start]) % MOD1;
        ll h2suf = (raw2 * invPow2[start]) % MOD2;

        if (h1pre == h1suf && h2pre == h2suf) {
            if (firstPrinted) cout << " ";
            cout << len;
            firstPrinted = true;
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // if you have multiple testcases: cin >> t;
    while (t--) Solve();
    return 0;
}
