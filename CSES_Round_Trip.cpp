#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
vector<int> parent, vis;
int start_node = -1, end_node = -1;

bool dfs(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue; // skip the edge to parent
        if (!vis[v]) {
            parent[v] = u;
            if (dfs(v, u)) return true;
        } else {
            // Found a cycle
            start_node = v;
            end_node = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    parent.assign(n+1, -1);
    vis.assign(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) break;
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start_node);
        for (int v = end_node; v != start_node; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(start_node);

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
}
