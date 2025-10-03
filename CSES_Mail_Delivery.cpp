/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<int> adj[],vector<bool> &vis){
    cout<<node<<" ";
    vis[node] = true;
    for(auto it : adj[node]){
        if(it != par && !vis[it]){
            dfs(it,node,adj,vis);
        }
    }
    cout<<node<<" ";
    
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    vector<bool> vis(n+1,false);

    for(int i = 0;i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,adj,vis);
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}