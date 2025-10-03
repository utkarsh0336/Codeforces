/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = 1e18;

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> adj[n+1];

    for(int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    // min-heap {dist, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // store up to k shortest distances for each node
    vector<vector<int>> dist(n+1);
    pq.push({0,1});

    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();

        // if we already have k distances for u, skip
        if(dist[u].size() >= k) continue;
        dist[u].push_back(d);

        // expand neighbors
        for(auto [v, w] : adj[u]) {
            pq.push({d+w, v});
        }
    }

    // print k shortest paths to n
    for(int x : dist[n]) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
