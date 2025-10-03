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

    vector<int> arr;
    for(auto it : mp){
        arr.push_back(it.second);
    }

    sort(begin(arr),end(arr));

    int ans = 0;
    for(int i = 0;i < arr.size(); i++){
        ans = max(ans,(arr.size()-i)*arr[i]);
    }
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
