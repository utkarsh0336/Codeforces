/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

stack<int> st;
vector<int> vis;

void dfs(int node,vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj);
        }
    }
    st.push(node);
}

void dfs2(int node,vector<int> adj[],vector<int> &temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs2(it,adj,temp);
        }
    }
}
 
void Solve(){
    int n , m;
    cin >> n >> m;
    vector<int> adj[n+1],radj[n+1];

    for(int i = 0;i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vis.clear();
    vis.resize(n+1, 0);
    for(int i = 1;i <= n; i++){
        if(!vis[i])
            dfs(i,adj);
    }
    vis.assign(n+1, 0);

    vector<vector<int>> result;
    int scc = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();
            if(!vis[node]){
                vector<int> temp;
                dfs2(node,radj,temp);
                result.push_back(temp);
                scc++;
            }
        

    }
    cout<<scc<<endl;
    // for(int i = 0;i < result.size(); i++){
    //     for(int j = 0; j < result[i].size(); j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector<int> ans(n+1,-1);

      int cnt = 1;
    for(int i = 0;i < result.size(); i++){
        for(int j = 0;j < result[i].size(); j++){
            ans[result[i][j]] = cnt;
        }
        cnt++;
    }
    for(int i = 1;i <= n; i++) cout<<ans[i]<<" ";
   


}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}