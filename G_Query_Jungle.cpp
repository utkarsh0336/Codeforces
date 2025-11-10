/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector<int> in, out, order;
int timer;

void dfs(int v, int p) {
    in[v] = timer++;
    order[in[v]] = v;
    for(auto u: adj[v]){
        if(u==p) continue;
        dfs(u,v);
    }
    out[v] = timer-1;
}

struct SegTree{
    int n;
    vector<int> tree, lazy;
    void init(int size){
        n = size;
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
    }
    void push(int v, int l, int r){
        if(lazy[v]){
            tree[v] = (r-l+1)-tree[v];
            if(l!=r){
                lazy[2*v]^=1;
                lazy[2*v+1]^=1;
            }
            lazy[v]=0;
        }
    }
    void update(int v, int l, int r, int ql, int qr){
        push(v,l,r);
        if(qr<l || r<ql) return;
        if(ql<=l && r<=qr){
            lazy[v]^=1;
            push(v,l,r);
            return;
        }
        int m=(l+r)/2;
        update(2*v,l,m,ql,qr);
        update(2*v+1,m+1,r,ql,qr);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
    int query(int v, int l, int r){
        push(v,l,r);
        return tree[v];
    }
};

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    adj.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    in.assign(n+1,0);
    out.assign(n+1,0);
    order.assign(n,0);
    timer=0;
    dfs(1,0);

    SegTree seg;
    seg.init(n);
    for(int i=0;i<n;i++){
        if(a[order[i]]==1) seg.update(1,0,n-1,i,i);
    }

    auto get_ans=[&](){
        return seg.query(1,0,n-1);
    };

    cout << get_ans() << "\n";

    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int v; cin >> v;
        seg.update(1,0,n-1,in[v],out[v]);
        cout << get_ans() << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) Solve();

    return 0;
}
