/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int x,y,k;
    cin >> x >> y >> k;

    cout<<((k*y + k + x - 3) / (x - 1) ) + k <<endl; 

    
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
