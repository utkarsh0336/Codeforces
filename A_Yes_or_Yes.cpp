/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0;i < s.size(); i++){
      if(s[i] == 'Y') cnt++;
      if(cnt > 1) break;
    }

    if(cnt != 2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
