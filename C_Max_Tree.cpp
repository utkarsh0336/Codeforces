/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (auto v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return order;
}

void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--, v--;

        if (u > v) swap(u, v); // enforce u < v

        if (y > x) {
            // prefer p[u] > p[v]
            adj[u].push_back(v);
        } else {
            // prefer p[v] > p[u]
            adj[v].push_back(u);
        }
    }

    vector<int> order = topoSort(n, adj);

    if ((int)order.size() < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // Assign permutation values in reverse topo order
    vector<int> p(n);
    int val = n;
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        p[order[i]] = val--;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
