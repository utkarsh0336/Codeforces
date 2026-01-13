/* Utkarsh Sahay */

// Portable replacement for bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <cstring>
#include <string>
#include <limits>
#include <climits>

using namespace std;

#define int long long

const int N = 100005 , M = 22;

vector<int> adj[N];
vector<int> articulationPoints;
vector<pair<int,int>> bridges;
vector<int> low(N),disc(N);
int timer = 1;

void dfs(int node,int par){
    low[node] = disc[node] = timer++;
    int no_of_child = 0;

    for(auto &child: adj[node]){
        if(disc[child] == 0){ // not visited
            dfs(child,node);
            no_of_child++;
            low[node] = min(low[node],low[child]);

            // Articulation Point
            if(par != 0 && low[child] >= disc[node]){
                articulationPoints.push_back(node);
            }

            // Bridge
            if(low[child] > disc[node]){
                bridges.push_back({node,child});
            }
        }
        else if(child != par){
            // backedge
            // cycle found
            low[node] = min(low[node],disc[child]);
        }
    }

    if(par == 0 && no_of_child >= 2){
        articulationPoints.push_back(node);
    }
    
}

void Solve() {
    int i,j,k,n,m,ans = 0,cnt = 0,sum = 0;

    cin >> n >> m;

    for(int i = 0;i < m; i++){
        int x,y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);

    for(auto point : articulationPoints) cout<<point<<" ";
    cout<<endl;
    for(auto edge : bridges) cout<<edge.first<<" "<<edge.second<<" | ";
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
