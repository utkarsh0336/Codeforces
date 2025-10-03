/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void Solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);

    int cnte = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    
    ll ans = 1e6;
    for(int i = 0;i < n; i++){
        if(a[i] % 2 == 0) cnte++;
        if(a[i] % k == 0){
            cout<<0<<endl;
            return;
        }
        ll num = k - (a[i] % k);
        ans = min(ans,num);
    }
    
    if(k == 4){
        if(cnte >= 2){
            ans = min(ans,0LL);
        }
        if(cnte == 1){
            ans = min(ans,1LL);
        }
        if(cnte == 0){
            ans = min(ans,2LL);
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