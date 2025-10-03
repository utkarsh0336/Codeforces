/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node,int par,vector<int>& subSize,vector<int> adj[]){
    subSize[node] = 1;
    for(auto it : adj[node]){
        if(it == par) continue;
        dfs(it,node,subSize,adj);
        subSize[node] += subSize[it];
    }
}

int centroid(int node,int par,int n,vector<int>& subSize,vector<int> adj[]){
    for(auto it : adj[node]){
        if(it != par){
            if(subSize[it] > n / 2){
                return centroid(it,node,n,subSize,adj);
            }
        }
    }
    return node;
}

void Solve(){
    int n;
    cin >> n;
    vector<int> adj[n+1];

    for(int i = 0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subSize(n+1,0);
    dfs(1,0,subSize,adj);

    cout << centroid(1,0,n,subSize,adj) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
