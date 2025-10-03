/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    string s;
    cin >> s;

    int ans = 0;
    for(int i = 0;i < s.size()-3; i++){
        bool isBear = false;
        for(int j = i+3;j < s.size(); j++){
            if(isBear || s.substr(j-3,4) == "bear"){
                isBear = true;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}