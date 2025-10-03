/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> vis;

void dfs(int node, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> adj[], vector<int> &temp) {
    vis[node] = 1;
    temp.push_back(node);   // collect SCC nodes
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs2(it, adj, temp);
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1], radj[n+1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vis.assign(n+1, 0);

    // First DFS on all nodes
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, adj);
    }

    vis.assign(n+1, 0);
    vector<vector<int>> result;
    int scc = 0;

    // Process nodes in order of finish time
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            vector<int> temp;
            dfs2(node, radj, temp);
            result.push_back(temp);
            scc++;
        }
    }

    if (scc == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        cout << result[1][0] << " " << result[0][0] << "\n";
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
