/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int a,b,n;
    cin >> a >> b >> n;

    int ans = 1;
    for(int i = n; i >= 1; i--){
        double len = min(b*1.0,(a*1.0) / (i*1.0));
        if(a % len != 0) ans++;
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
