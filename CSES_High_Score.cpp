/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
};

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<vector<int>> adj(n+1), radj(n+1); // for reachability check

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<long long> dist(n+1, LLONG_MIN);
    dist[1] = 0;

    // Bellman-Ford for max path
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MIN && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Reachability check
    vector<bool> from1(n+1, false), toN(n+1, false);

    // DFS/BFS from node 1
    {
        queue<int> q;
        q.push(1);
        from1[1] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (!from1[v]) {
                    from1[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // DFS/BFS from node n in reversed graph
    {
        queue<int> q;
        q.push(n);
        toN[n] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : radj[u]) {
                if (!toN[v]) {
                    toN[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // Detect positive cycle reachable from 1 and can reach n
    for (auto &e : edges) {
        if (dist[e.u] != LLONG_MIN && dist[e.u] + e.w > dist[e.v]) {
            if (from1[e.v] && toN[e.v]) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    cout << dist[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
