/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0;i < s.size(); i++){
        if(s[i] == 's') continue;
        else if(s[i] == 'u' && (i == 0 || i == s.size()-1)){
            ans++;
            s[i] = 's';
        }
        else if(s[i-1] == 'u'){
            ans++;
            s[i-1] = 's';
        }
        else if(s[i+1] == 'u'){
            ans++;
            s[i+1] = 's';
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
