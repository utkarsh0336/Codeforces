#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> S(n), T(n);
        for (auto &x : S) cin >> x;
        for (auto &x : T) cin >> x;

        unordered_map<long long,int> freqS, freqT;
        for (auto &x : S) freqS[x % k]++;
        for (auto &x : T) freqT[x % k]++;

        if (freqS == freqT) cout << "YES\n";
        else cout << "NO\n";
    }
}
