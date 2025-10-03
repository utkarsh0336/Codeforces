/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

const long long INF = 1e18;  

void Solve(){
    int n , m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0;i < m; i++){
        int a , b , c;
        cin >> a >> b >> c;

        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> parent(n+1),result(n+1,INF);

    pq.push({0,1});
    result[1] = 0;
    parent[1] = -1;

    while(!pq.empty()){
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for(auto it : adj[u]){
            int v = it.first;
            int wt = it.second;

            if(dist + wt < result[v]){
                result[v] = dist + wt;
                parent[v] = u;
                pq.push({dist + wt , v});
            }
        }
    }

    if(result[n] == INF){
        cout<<-1<<endl;
        return;
    }

    vector<int> path;
    int node = n;
    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }

    reverse(begin(path),end(path));
    for(auto ans : path) cout<<ans<<" ";
    
}
 
int32_t main(){

    // int t = 1;
    // cin >> t;
    // while(t--){
        Solve();
    // }
 
    return 0;
}