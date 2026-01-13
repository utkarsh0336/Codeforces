/* Utkarsh Sahay */

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> vis;
vector<int> dp, depth;
vector<vector<int>> adj;

/*
 Q. -> Find the smallest height of a node that can be visited
       from a subtree of x (Low-link values)
*/

void dfs(int node, int par, int d) {
    vis[node] = true;
    depth[node] = dp[node] = d;

    for (auto ngbr : adj[node]) {
        if (!vis[ngbr]) {
            dfs(ngbr, node, d + 1);
            dp[node] = min(dp[node], dp[ngbr]);
        }
        else if (ngbr != par) {
            // back-edge
            dp[node] = min(dp[node], depth[ngbr]);
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, false);
    dp.resize(n + 1);
    depth.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1, 0);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << dp[i] << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}
