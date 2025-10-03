/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = 1e18;
 
void Solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i = 0;i < m; i++){
        int u,v,c;
        cin >> u >> v >> c;

        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    int sum = 0;
    vector<int> vis(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,1});
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum |= cost;

        for(auto it : adj[node]){
            if(vis[it.first] == 0){
                pq.push({it.second,it.first});
            }
        }
    }

    cout<<sum<<endl;
}
 
int32_t main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}