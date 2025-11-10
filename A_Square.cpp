/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int a , b , c, d;
    cin >> a >> b >> c >> d;

    if(a == b && b == c && c == d && a == d){
        cout<<"Yes"<<endl;
    }
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
