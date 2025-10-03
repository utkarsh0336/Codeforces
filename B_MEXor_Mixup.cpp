/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int a, b;
    cin >> a >> b;
    int xorr = 0;
    int n = a-1;
    if(n % 4 == 0){
        xorr = n;
    }
    if(n % 4 == 1){
        xorr = 1;
    }
    if(n % 4 == 2){
        xorr = n + 1;
    }
    if(n % 4 == 3){
        xorr = 0;
    }

    if(xorr == b) {
        cout<<a<<endl;
        return;
    }

    if((xorr ^ b) == a){
        cout<<a+2<<endl;
    }
    else{
        cout<<a+1<<endl;    
    }
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
