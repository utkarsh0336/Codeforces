/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n;
    cin >> n;
    string s; cin >> s;
    string st = s;
    sort(begin(s),end(s));
    int cnt = 0;
    for(int i = 0;i < n; i++){
        if(s[i] != st[i]){
            cnt++;
        }
    }

    cout<<cnt / 2<<endl;
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