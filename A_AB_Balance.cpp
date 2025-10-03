/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    string s;
    cin >> s;

    if(s[0] == s[s.size()-1]){
        cout<<s<<endl;
        return;
    }

    char ch = s[0];
    s.pop_back();
    s.push_back(ch);
    cout<<s<<endl;


}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}