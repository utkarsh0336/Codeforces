/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int m =  998244353;
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < n; i++) cin >> b[i];

    int ans = 2;
    for(int i = 1;i < n; i++){
        if(max(a[i-1],b[i-1]) <= min(a[i],b[i])){
            ans *= 2;
            ans %= m;
        }
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
