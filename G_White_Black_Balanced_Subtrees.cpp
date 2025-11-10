/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans = 0;

pair<int,int> solve(int node, unordered_map<int, vector<int>> &adj, string &s) {
    int cntb = 0, cntw = 0;

    for (auto &child : adj[node]) {
        auto [b, w] = solve(child, adj, s);
        cntb += b;
        cntw += w;
    }

    if (s[node - 1] == 'W') cntw++;
    else cntb++;

    if (cntb == cntw) ans++;
    return {cntb, cntw};
}

void Solve() {
    int n;
    cin >> n;

    vector<int> pars(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> pars[i];
    }

    string s;
    cin >> s;

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n - 1; i++) {
        adj[pars[i]].push_back(i + 2); // 1-based tree
    }

    ans = 0;
    solve(1, adj, s);
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
