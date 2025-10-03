/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<int> a(n),b(m);
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < m; i++) cin >> b[i];
    cout<<n+m<<endl;
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
