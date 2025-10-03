/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n,p;
    cin >> n >> p;
    vector<int> r(n),c(n);

    for(int i = 0;i < n; i++){
        cin >> r[i];
    }

    for(int i = 0;i < n; i++){
        cin >> c[i];
    }

    vector<pair<int,int>> v;
    for(int i = 0;i < n ; i++){
        pair<int,int> p = {c[i],r[i]};
        v.push_back(p);
    }

    sort(begin(v),end(v));

    int maximum_cost =  0;
    int already_shared = 1;
    for(auto it : v){
        int sharing_cost = it.first;
        int can_be_shared = it.second;

        if(sharing_cost >= p) break;

        if(already_shared + can_be_shared > n){
            maximum_cost += (n - already_shared) * sharing_cost;
            already_shared = n;
            break;
        }
        else{
            maximum_cost += (sharing_cost * can_be_shared);
            already_shared += can_be_shared;
        }
    }
    maximum_cost += (n - already_shared) * p;
    cout<<maximum_cost<<endl;

}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}