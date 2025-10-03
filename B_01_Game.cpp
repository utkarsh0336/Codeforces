/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    string s;
    cin >> s;

    int n = s.size();
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0;i < n; i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    
    int cnt = min(cnt0,cnt1);
    
    if(cnt % 2 == 1){
      cout<<"DA"<<endl;
      return;
    }
    
    cout<<"NET"<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}