/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
// #define int long long

void Solve(){
    int r,x,d,n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == '1'){
            r = max(0,r-d);
            ans++;
        }
        else{
            if(r < x){
                r = max(0,r-d);
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
