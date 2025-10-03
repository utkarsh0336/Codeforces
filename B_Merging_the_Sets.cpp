/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,vector<int>> mp;
    for(int i = 0;i < n;i++){
        int l;
        cin >> l;
        for(int j = 0;j < l; j++){
            int num;
            cin >> num;
            mp[num].push_back(i);
        }
    }

    bool all = true;
    set<int> spec_set;
    for(int i = 1; i <= m; i++){
        if(mp[i].size() == 1){
            spec_set.insert(mp[i][0]);
        }
        if(!mp[i].size()) all = false;
    }

    int opt = n - spec_set.size();
    if(all && opt >= 2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
