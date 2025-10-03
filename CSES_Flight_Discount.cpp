/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

struct State {
    long long dist;
    int node, used;
    bool operator>(const State &other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);
    for (int i=0; i<m; i++) {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    const long long INF = 1e18;
    vector<vector<long long>> dist(n+1, vector<long long>(2, INF));
    dist[1][0] = 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0,1,0});

    while (!pq.empty()) {
        auto [d,u,used] = pq.top(); pq.pop();
        if (d != dist[u][used]) continue;

        for (auto [v,w] : adj[u]) {
            // normal edge
            if (d + w < dist[v][used]) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            // use coupon if not yet used
            if (!used && d + w/2 < dist[v][1]) {
                dist[v][1] = d + w/2;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << dist[n][1] << "\n";
    return 0;
}
