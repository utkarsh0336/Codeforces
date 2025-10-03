/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    sort(begin(a),end(a));

    int ans = INT_MIN;
    for(int i = 0;i < n-1; i += 2){
        ans = max(ans,abs(a[i+1] - a[i]));
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
