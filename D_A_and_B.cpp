/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int> posA, posB;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') posA.push_back(i);
        else posB.push_back(i);
    }

    auto cost_to_group = [&](const vector<int>& pos) -> long long {
        if (pos.empty()) return (long long)4e18;
        int m = pos.size();
        int mid = m / 2;
        long long cost = 0;
        long long base = pos[mid] - mid;
        for (int i = 0; i < m; ++i) {
            cost += llabs(pos[i] - (base + i));
        }
        return cost;
    };

    long long ans = min(cost_to_group(posA), cost_to_group(posB));
    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
