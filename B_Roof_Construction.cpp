/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    int a = n-1;
    int msb = floor(log2(a));
    for(int i = (1 << msb) - 1; i >= 0; i--){
        cout<<i<<" ";
    }
    for(int i = (1 << msb); i < n; i++){
        cout<<i<<" ";
    }
    cout<<endl;
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
