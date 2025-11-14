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

    for(int i = 0;i < n-1; i++){
        if(i % 2 != 0 && a[i] != a[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
