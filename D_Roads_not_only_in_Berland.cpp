/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent,rank;
    public:
        DSU(int n){
            for(int i = 0;i <= n; i++){
                parent.push_back(i);
                rank.push_back(0);
            }
        }

        int Find(int node){
            if(parent[node] == node) return node;
            return parent[node] = Find(parent[node]);
        }

        void Union(int a,int b){
            int a_par = Find(a);
            int b_par = Find(b);

            if(a_par == b_par) return;

            if(rank[a_par] < rank[b_par]){
                parent[a_par] = b_par;
            } 
            else if(rank[a_par] > rank[b_par]){
                parent[b_par] = a_par;
            }
            else {
                parent[b_par] = a_par;
                rank[a_par]++;
            }
        }

};
void Solve(){
    int n;
    cin >> n;

    DSU d(n);

    vector<pair<int,int>> old_roads;

    for(int i = 0;i < n-1; i++){
        int u,v;
        cin >> u >> v;

        if(d.Find(u) != d.Find(v)){
            d.Union(u,v);
        }
        else{
            old_roads.push_back({u,v});
        }
    }

    set<int> st;
    vector<int> temp;

    for(int i = 1;i <= n; i++){
        if(st.find(d.Find(i)) == st.end()){
            st.insert(d.Find(i));
            temp.push_back(d.Find(i));
        }
    }

    cout<<temp.size()-1<<endl;
    for(int i = 0;i < temp.size()-1; i++){
        cout<<old_roads[i].first<<" "<<old_roads[i].second<<" "<<temp[i]<<" "<<temp[i+1]<<endl;
    }
}
 
int main(){

    // int t;
    // cin >> t;
    // while(t--){
        Solve();
    // }
 
    return 0;
}