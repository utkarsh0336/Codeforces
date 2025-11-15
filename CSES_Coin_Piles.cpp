/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int a,b;
    cin >> a >> b;
    int maxi = max(a,b);
    int mini = min(a,b);

    if((maxi + mini) % 3 == 0 && maxi <= (2 * mini)){
        cout<<"YES"<<endl;
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
