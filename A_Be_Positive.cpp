/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> mp;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 0;
    ans += ((mp[-1] % 2) * 2);
    ans += mp[0];
    cout<<ans<<endl;
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
