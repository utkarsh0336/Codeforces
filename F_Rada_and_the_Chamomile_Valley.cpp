// Utkarsh Sahay - Solution
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> eu(m+1), ev(m+1);
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            eu[i]=u; ev[i]=v;
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        vector<int> tin(n+1,0), low(n+1,0), timer(1);
        vector<char> vis(n+1,0);
        vector<char> isBridge(m+1,0);
        function<void(int,int)> dfs = [&](int v,int pe){
            vis[v]=1;
            tin[v]=low[v]=timer[0]++;
            for(auto [to,idx]: adj[v]){
                if(idx==pe) continue;
                if(vis[to]){
                    low[v]=min(low[v], tin[to]);
                } else {
                    dfs(to, idx);
                    low[v]=min(low[v], low[to]);
                    if(low[to] > tin[v]) isBridge[idx]=1;
                }
            }
        };
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,-1);
        vector<int> comp(n+1,0);
        int compCnt=0;
        for(int i=1;i<=n;i++){
            if(comp[i]) continue;
            compCnt++;
            stack<int> st;
            st.push(i);
            comp[i]=compCnt;
            while(!st.empty()){
                int v=st.top(); st.pop();
                for(auto [to,idx]: adj[v]){
                    if(isBridge[idx]) continue;
                    if(!comp[to]){ comp[to]=compCnt; st.push(to); }
                }
            }
        }
        vector<vector<pair<int,int>>> tree(compCnt+1);
        for(int i=1;i<=m;i++){
            if(isBridge[i]){
                int a=comp[eu[i]], b=comp[ev[i]];
                tree[a].push_back({b,i});
                tree[b].push_back({a,i});
            }
        }
        int c1 = comp[1], cN = comp[n];
        vector<int> requiredEdges;
        if(c1 != cN){
            vector<int> parent(compCnt+1,-1), pEdge(compCnt+1,-1);
            queue<int> q;
            q.push(c1);
            parent[c1]=0;
            while(!q.empty()){
                int v=q.front(); q.pop();
                for(auto [to,idx]: tree[v]){
                    if(parent[to]==-1){
                        parent[to]=v;
                        pEdge[to]=idx;
                        q.push(to);
                    }
                }
            }
            int cur=cN;
            while(cur!=c1){
                requiredEdges.push_back(pEdge[cur]);
                cur=parent[cur];
            }
        }
        int qq; cin>>qq;
        if(requiredEdges.empty()){
            for(int i=0;i<qq;i++){
                int c;cin>>c;
                cout<<-1<<(i+1==qq?'\n':' ');
            }
            continue;
        }
        const int INF = 1e9;
        vector<int> bestDist(n+1, INF), bestIdx(n+1, INF);
        deque<int> dq;
        for(int idx: requiredEdges){
            int u=eu[idx], v=ev[idx];
            if(bestDist[u]>0){ bestDist[u]=0; bestIdx[u]=idx; dq.push_back(u); }
            else if(bestDist[u]==0 && idx < bestIdx[u]){ bestIdx[u]=idx; dq.push_back(u); }
            if(bestDist[v]>0){ bestDist[v]=0; bestIdx[v]=idx; dq.push_back(v); }
            else if(bestDist[v]==0 && idx < bestIdx[v]){ bestIdx[v]=idx; dq.push_back(v); }
        }
        while(!dq.empty()){
            int v=dq.front(); dq.pop_front();
            for(auto [to,idx]: adj[v]){
                int candD = bestDist[v] + 1;
                int candI = bestIdx[v];
                if(candD < bestDist[to]){
                    bestDist[to]=candD;
                    bestIdx[to]=candI;
                    dq.push_back(to);
                } else if(candD == bestDist[to] && candI < bestIdx[to]){
                    bestIdx[to]=candI;
                    dq.push_back(to);
                }
            }
        }
        for(int i=0;i<qq;i++){
            int c;cin>>c;
            cout<<bestIdx[c]<<(i+1==qq?'\n':' ');
        }
    }
    return 0;
}
