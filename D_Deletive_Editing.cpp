/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    string s,t;
    cin >> s >> t;

    int i = 0,j = 0;
    unordered_map<char,int> smp,tmp;

    for(auto ch : s) smp[ch]++;
    for(auto ch : t) tmp[ch]++;

    while(i < s.size() && j < t.size()){
        if(s[i] == t[j]){
            if(smp[s[i]] < tmp[t[j]]){
                break;
            }
            if(smp[s[i]] == tmp[t[j]]){
                tmp[t[j]]--;
                j++;
            }
        }
        smp[s[i]]--;
        i++;
    }

    if(j >= t.size()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}