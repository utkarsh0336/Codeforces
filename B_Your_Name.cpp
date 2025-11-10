/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    unordered_map<char,int> mp;
    bool found = true;
    for(auto ch : s){
        mp[ch]++;
    }

    for(auto ch : t){
        if(mp.find(ch) == mp.end()){
            found = false;
            break;
        }
        else{
            mp[ch]--;
            if(mp[ch] == 0){
                mp.erase(ch);
            }
        }
    }

    found = mp.empty();

    if(!found) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

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
