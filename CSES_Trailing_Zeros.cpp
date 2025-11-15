/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;

    int ans = 0;
    while(n){
        ans += (n / 5);
        n /= 5;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
