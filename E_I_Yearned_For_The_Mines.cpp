/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1,0);

    int maxD = 0, maxN = 1;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
        if(deg[u] > maxD){
            maxD = deg[u];
            maxN = u;
        }
        if(deg[v] > maxD){
            maxD = deg[v];
            maxN = v;
        }
    }

    // use max-heap
    priority_queue<pair<int,int>> pq;
    pq.push({maxD, maxN});

    vector<pair<int,int>> res;
    vector<bool> checked(n+1, false);

    int ans = 0;
    while(!pq.empty()){
        int degree = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(checked[node]) continue; 
        checked[node] = true;

        if(degree <= 1){
            res.push_back({1,node});
            ans++;
            continue;
        }

        res.push_back({1,node});
        ans++;
        res.push_back({2,node});
        ans++;

        for(int v : adj[node]){
            if(!checked[v]){
                deg[v]--;
                pq.push({deg[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!checked[i] && deg[i] > 0){
            res.push_back({1,i});
            ans++;
        }
    }

    cout << ans << "\n";
    for(auto &r : res){
        cout << r.first << " " << r.second << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
