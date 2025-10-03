/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> dist(n+1, -1);
    vector<int> parent(n+1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << dist[n] << "\n";

    vector<int> path;
    for (int curr = n; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << "\n";
}

int main() {
    Solve();
    return 0;
}
