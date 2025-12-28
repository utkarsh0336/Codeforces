/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0;i < n-1; i++){
        if(s[i] > s[i+1]){
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
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
