/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n , m , q;
    const int INF = 1e18;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c); // two-way roads
    }

    for(int i = 1; i <= n; i++) dist[i][i] = 0;

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << ((dist[a][b] == INF) ? -1 : dist[a][b]) << "\n";
    }
}

int32_t main(){
    Solve();
    return 0;
}
