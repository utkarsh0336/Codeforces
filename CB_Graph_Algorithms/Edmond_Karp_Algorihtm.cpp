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

bool bfs(vector<vector<int>> &residualCapacity,int source,int sink,int n,vector<int> &parent){ // n is the number of vertices
    vector<bool> visited(n,false);
    queue<int> q;
    visited[source] = true;
    q.push(source);
    bool foundAugmentedPath = false;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0;v < n; v++){
            if(!visited[v] && residualCapacity[u][v] > 0){
                parent[v] = u;
                visited[v] = true;
                q.push(v);

                if(v == sink){
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}

void printAugmentedPaths(vector<vector<int>> &augmentedPaths){
    for(int i = 0;i < augmentedPaths.size(); i++){
        for(int j = 0;j < augmentedPaths[i].size(); j++){
            cout << augmentedPaths[i][j] << ", ";
        }
        cout<<endl;
    }
}

int maxFlow(vector<vector<int>> &capacity,int source,int sink,int v){
    vector<vector<int>> residualCapacity(v,vector<int>(v));
    vector<int> parent(1000);
    vector<vector<int>> augementedPaths;

    int max_flow = 0;

    for(int i = 0;i < v; i++){
        for(int j = 0;j < v; j++){
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    while(bfs(residualCapacity,source,sink,v,parent)){
        vector<int> currentAugmentedPath;
        int flow = INT_MAX;
        int v = sink;

        while(v != source){
            currentAugmentedPath.push_back(v);
            int u = parent[v];

            if(flow > residualCapacity[u][v]){
                flow = residualCapacity[u][v];
            }
            v = u;
        }

        currentAugmentedPath.push_back(source);
        reverse(begin(currentAugmentedPath),end(currentAugmentedPath));
        augementedPaths.push_back(currentAugmentedPath);
        
        max_flow += flow;

        v = sink;
        while(v != source){
            int u = parent[v];
            residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v = u;
        }
    }

    printAugmentedPaths(augementedPaths);

    return max_flow;
}

void Solve() {
    int v , e;
    cin >> v >> e;

    vector<vector<int>> capacity(v,vector<int>(v));

    for(int i = 0;i < e; i++){
        int u,v,c;
        cin >> u >> v >> c;

        capacity[u][v] = c;
    }
    
    cout<<maxFlow(capacity,0,1,v);
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
