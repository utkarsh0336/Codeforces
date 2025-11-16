/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int g,c,l;
    cin >> g >> c >> l;

    int maxi = max({g,c,l});
    int mini = min({g,c,l});
    int sum = g + c + l;

    int median = sum - (maxi + mini);

    if(maxi - mini >= 10) cout<<"check again"<<endl;
    else cout<<"final "<<median<<endl;
    
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
