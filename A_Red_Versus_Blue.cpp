/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n , r, b;
    cin >> n >> r >> b;

    vector<int> parts(b+1,0);
    int cntb = b;
    
    for(int i = 0;i < r; i++){
        parts[(i % (b+1))]++;
    }
    string ans = "";
    for(int i = 0;i < b+1; i++){
        while(parts[i]--){
            ans += "R";
        }
        if(cntb){
            ans += "B";
            cntb--;
        }
    }
    
    while(cntb--){
        ans += "B";
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
