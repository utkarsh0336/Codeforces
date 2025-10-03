/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    string s;
    cin >> s;
    int n = s.size();

    int cnt0 = 0 , cnt1 = 0, ans = 0;
    for(auto ch : s){
        if(ch == '0') cnt0++;
        else cnt1++;
    }

    for(int i = 0;i < n; i++){
        auto ch = s[i];
        if(ch == '0'){
            if(cnt1 > 0){
                cnt1--;
            }
            else{
                ans += (n - i);
                break;
            }
        }
        else{
            if(cnt0 > 0){
                cnt0--;
            }
            else{
                ans += (n - i);
                break;
            }
        }
    }

    cout<<ans<<endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}