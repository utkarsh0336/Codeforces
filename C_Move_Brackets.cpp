/*Utkarsh Sahay*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;

    int op = 0;

    for(auto ch : s){
        if(ch == '(') op++;
        else {
            if(op > 0) op--;
            else{
                ans++;
            }
        }
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
