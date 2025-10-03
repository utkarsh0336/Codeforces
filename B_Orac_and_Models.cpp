/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1;i <= n; i++) cin>>a[i];

    vector<int> dp(n+1,1);
    int ans = 1;

    for(int i = 1;i <= n; i++){
        for(int j = 2 * i; j <= n; j += i){
            if(a[j] > a[i]){
                dp[j] = max(dp[j] , 1 + dp[i]);
            }
            ans = max(ans,dp[j]);
        }
    }

    cout<<ans<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}