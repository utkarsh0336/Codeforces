/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

stack<int> st;
vector<int> vis;

// Step 1: DFS to fill stack for Kosaraju
void fillStackDfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) fillStackDfs(it, adj, vis);
    }
    st.push(node);
}

// Step 2: DFS to collect nodes in SCC
void dfsSCC(int node, vector<vector<int>> &radj, vector<int> &vis, vector<int> &component) {
    vis[node] = 1;
    component.push_back(node);
    for (auto it : radj[node]) {
        if (!vis[it]) dfsSCC(it, radj, vis, component);
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++) cin >> coins[i];

    vector<vector<int>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    // Kosaraju Step 1: fill stack
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) fillStackDfs(i, adj, vis);

    // Kosaraju Step 2: reverse DFS to find SCCs
    vis.assign(n + 1, 0);
    vector<int> nodeToSCC(n + 1); // node -> SCC id
    vector<int> SCCSum;           // sum of coins in SCC
    int SCCcount = 0;

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!vis[node]) {
            vector<int> component;
            dfsSCC(node, radj, vis, component);
            int sum = 0;
            for (auto x : component) {
                nodeToSCC[x] = SCCcount;
                sum += coins[x];
            }
            SCCSum.push_back(sum);
            SCCcount++;
        }
    }

    // Step 3: Build DAG of SCCs
    vector<vector<int>> dag(SCCcount);
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            int sccU = nodeToSCC[u], sccV = nodeToSCC[v];
            if (sccU != sccV) {
                dag[sccU].push_back(sccV);
            }
        }
    }

    // Remove duplicates in DAG edges
    for (int i = 0; i < SCCcount; i++) {
        sort(dag[i].begin(), dag[i].end());
        dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }

    // Step 4: DP on DAG to get max coins
    vector<int> dp(SCCcount, 0);
    function<int(int)> dfsDP = [&](int u) {
        if (dp[u] != 0) return dp[u];
        int maxNext = 0;
        for (auto v : dag[u]) {
            maxNext = max(maxNext, dfsDP(v));
        }
        dp[u] = SCCSum[u] + maxNext;
        return dp[u];
    };

    int ans = 0;
    for (int i = 0; i < SCCcount; i++) {
        ans = max(ans, dfsDP(i));
    }

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}

