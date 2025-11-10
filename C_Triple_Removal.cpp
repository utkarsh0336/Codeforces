/* Debug build for triple-removal DP (instrumented) */
/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long INF = (long long)4e18;

struct Node {
    long long dp[3][3];
    vector<int> first[2], last[2];
    int len;
    Node() {
        len = 0;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) dp[i][j] = INF;
    }
};

int triple_cost_array(array<int,3> pos) {
    sort(pos.begin(), pos.end());
    return min(pos[1]-pos[0], pos[2]-pos[1]);
}

bool debug_this_query = false;
int debug_print_limit = 1000000;
int debug_counter = 0;

void print_node(const string &name, const Node &nd) {
    cout << "NODE " << name << " len=" << nd.len << "\n";
    cout << " dp:\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (nd.dp[i][j] >= INF/2) cout << "INF ";
            else cout << nd.dp[i][j] << " ";
        }
        cout << "\n";
    }
    for(int b=0;b<2;b++){
        cout << " first["<<b<<"]:";
        for(int x: nd.first[b]) cout << " " << x;
        cout << "\n";
        cout << " last["<<b<<"]:";
        for(int x: nd.last[b]) cout << " " << x;
        cout << "\n";
    }
    cout << "----\n";
}

Node merge_node_debug(const Node &L, const Node &R) {
    Node nd;
    nd.len = L.len + R.len;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) nd.dp[i][j] = INF;

    // maintain first/last (first from left then right up to 2)
    for(int b=0;b<2;b++){
        nd.first[b].clear();
        for(int x: L.first[b]) if((int)nd.first[b].size()<2) nd.first[b].push_back(x);
        for(int x: R.first[b]) if((int)nd.first[b].size()<2) nd.first[b].push_back(L.len + x);
        nd.last[b].clear();
        for(int x: R.last[b]) if((int)nd.last[b].size()<2) nd.last[b].push_back(L.len + x);
        for(int i=(int)L.last[b].size()-1;i>=0;i--) if((int)nd.last[b].size()<2) nd.last[b].push_back(L.last[b][i]);
    }

    // try all state combinations
    for(int r0L=0;r0L<3;r0L++){
        for(int r1L=0;r1L<3;r1L++){
            if(L.dp[r0L][r1L] >= INF) continue;
            for(int r0R=0;r0R<3;r0R++){
                for(int r1R=0;r1R<3;r1R++){
                    if(R.dp[r0R][r1R] >= INF) continue;
                    long long base = L.dp[r0L][r1L] + R.dp[r0R][r1R];
                    int tot0 = r0L + r0R;
                    int tot1 = r1L + r1R;

                    // case: carry leftovers if both <3
                    if(tot0 < 3 && tot1 < 3) {
                        nd.dp[tot0][tot1] = min(nd.dp[tot0][tot1], base);
                    }

                    // cross zeros
                    if(tot0 >= 3) {
                        long long best = INF;
                        if((int)L.last[0].size()>=2 && (int)R.first[0].size()>=1) {
                            array<int,3> arr = {L.last[0][(int)L.last[0].size()-2],
                                               L.last[0].back(),
                                               L.len + R.first[0][0]};
                            best = min(best, (long long)triple_cost_array(arr));
                        }
                        if((int)L.last[0].size()>=1 && (int)R.first[0].size()>=2) {
                            array<int,3> arr = {L.last[0].back(),
                                               L.len + R.first[0][0],
                                               L.len + R.first[0][1]};
                            best = min(best, (long long)triple_cost_array(arr));
                        }
                        if(best < INF && tot0-3 < 3 && tot1 < 3) {
                            nd.dp[tot0-3][tot1] = min(nd.dp[tot0-3][tot1], base + best);
                        }
                    }

                    // cross ones
                    if(tot1 >= 3) {
                        long long best = INF;
                        if((int)L.last[1].size()>=2 && (int)R.first[1].size()>=1) {
                            array<int,3> arr = {L.last[1][(int)L.last[1].size()-2],
                                               L.last[1].back(),
                                               L.len + R.first[1][0]};
                            best = min(best, (long long)triple_cost_array(arr));
                        }
                        if((int)L.last[1].size()>=1 && (int)R.first[1].size()>=2) {
                            array<int,3> arr = {L.last[1].back(),
                                               L.len + R.first[1][0],
                                               L.len + R.first[1][1]};
                            best = min(best, (long long)triple_cost_array(arr));
                        }
                        if(best < INF && tot0 < 3 && tot1-3 < 3) {
                            nd.dp[tot0][tot1-3] = min(nd.dp[tot0][tot1-3], base + best);
                        }
                    }
                }
            }
        }
    }

    if (debug_this_query && debug_counter < debug_print_limit) {
        cout << "=== MERGE (L.len="<<L.len<<", R.len="<<R.len<<") ===\n";
        print_node("LEFT", L);
        print_node("RIGHT", R);
        print_node("RESULT", nd);
        debug_counter++;
    }

    return nd;
}

struct SegTree {
    int n;
    vector<Node> st;
    SegTree(int n=0){ init(n); }
    void init(int N){ n=N; st.assign(4*N+5, Node()); }
    void build(const vector<int>& a, int p, int l, int r) {
        if(l==r) {
            Node nd; nd.len = 1;
            for(int i=0;i<3;i++) for(int j=0;j<3;j++) nd.dp[i][j]=INF;
            if(a[l]==0) { nd.dp[1][0]=0; nd.first[0]={0}; nd.last[0]={0}; }
            else { nd.dp[0][1]=0; nd.first[1]={0}; nd.last[1]={0}; }
            st[p]=nd;
            return;
        }
        int m=(l+r)/2;
        build(a, p<<1, l, m);
        build(a, p<<1|1, m+1, r);
        st[p] = merge_node_debug(st[p<<1], st[p<<1|1]);
    }
    Node query(int p, int l, int r, int ql, int qr) {
        if(ql<=l && r<=qr) return st[p];
        int m=(l+r)/2;
        if(qr<=m) return query(p<<1, l, m, ql, qr);
        if(ql>m) return query(p<<1|1, m+1, r, ql, qr);
        Node L = query(p<<1, l, m, ql, qr);
        Node R = query(p<<1|1, m+1, r, ql, qr);
        // When debugging the first query, set debug flag so merge prints
        return merge_node_debug(L, R);
    }
};

void Solve() {
    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];

    SegTree seg(n);
    seg.init(n);
    seg.build(a,1,1,n);

    // we'll print debug only for the first query of this test case
    bool first_query_done = false;
    while(q--){
        int l,r; cin >> l >> r;
        if(!first_query_done) {
            debug_this_query = true;
            debug_counter = 0;
        } else {
            debug_this_query = false;
        }
        Node ansNode = seg.query(1,1,n,l,r);
        long long ans = ansNode.dp[0][0];
        if(ans>=INF) cout << -1 << "\n";
        else cout << ans << "\n";
        first_query_done = true;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        Solve();
    }
    return 0;
}
