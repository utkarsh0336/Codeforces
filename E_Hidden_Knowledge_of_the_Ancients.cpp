/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

long long count_at_most_k_with_maxlen(const vector<int>& a, int K, int X) {
    if (K < 0 || X <= 0) return 0;
    int n = a.size();
    unordered_map<int,int> freq;
    freq.reserve(n * 2);
    freq.max_load_factor(0.7);

    int distinct = 0;
    int L = 0;
    long long res = 0;
    for (int R = 0; R < n; ++R) {
        if (freq[a[R]] == 0) ++distinct;
        ++freq[a[R]];

        while (distinct > K) {
            --freq[a[L]];
            if (freq[a[L]] == 0) {
                freq.erase(a[L]);
                --distinct;
            }
            ++L;
        }

        int minStartByLen = R - X + 1;
        int start_low = max(L, minStartByLen);
        if (start_low <= R) res += (R - start_low + 1);
    }
    return res;
}

void Solve(){
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = 
        count_at_most_k_with_maxlen(a, k, r)
      - count_at_most_k_with_maxlen(a, k, l - 1)
      - count_at_most_k_with_maxlen(a, k - 1, r)
      + count_at_most_k_with_maxlen(a, k - 1, l - 1);

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
