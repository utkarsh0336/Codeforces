/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;

    char s = '9';

    string st = to_string(n);
    for(auto ch : st){
        if(ch < s){
            s = ch;
        }
    }

    int ans = s - '0';
    cout<<ans<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}