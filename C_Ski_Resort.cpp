/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n,k,q;
    cin >> n >> k >> q;

    vector<int> a(n),psum(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
        if(a[i] > q) {
            psum[i] = 0;
        }
        else{
            psum[i] = 1;
        }
    }
    int c = 0;
    int ans = 0;
    for(int i = 0;i < n; i++){
        if(psum[i] != 0){
            c++;
        }
        else{
            int len = (c - k + 1);
            ans += (len > 0) ? (len * (len + 1)) / 2 : 0;
            c = 0;
        }
    }

    if(c > 0){
        int len = (c - k + 1);
        ans += (len > 0) ? (len * (len + 1)) / 2 : 0;
    }

    cout<<ans<<endl;

    
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