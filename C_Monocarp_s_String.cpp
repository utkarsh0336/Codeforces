/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> acnt(n, 0), bcnt(n, 0);
    acnt[0] = (s[0] == 'a');
    bcnt[0] = (s[0] == 'b');
    
    int totalA = (s[0] == 'a') ? 1 : 0;
    int totalB = (s[0] == 'b') ? 1 : 0;
    
    for(int i = 1; i < n; i++){
        if(s[i] == 'a'){
            acnt[i] = 1 + acnt[i-1];
            totalA++;
        }
        else{
            acnt[i] = 0;
            totalB++;
        }
    }

    if(totalB == 0 || totalA == 0) {
      cout<<-1<<endl;
      return;
    }
    
    for(int i = 1; i < n; i++){
        if(s[i] == 'b'){
            bcnt[i] = 1 + bcnt[i-1];
        }
        else{
            bcnt[i] = 0;
        }
    }


    if (totalA == totalB) {
        cout << 0 << '\n';
        return;
    }
  
  // cout<<"A cnt: "<<totalA<<endl;
  // cout<<"B cnt: "<<totalB<<endl;
  
  // for(auto acn : acnt) cout<<acn<<" ";
  // cout<<endl;
  // for(auto b : bcnt) cout<<b<<" ";
  // cout<<endl;
  


    int diff = abs(totalA - totalB);

    if(totalA > totalB){
        for(int i = 0;i < n; i++){
            if(acnt[i] == diff){
                cout<<diff<<endl;
                return;
            }
        }
    }
    else{
        for(int i = 0;i < n; i++){
            if(bcnt[i] == diff){
                cout<<diff<<endl;
                return;
            }
        }
    }


    cout<<-1<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
