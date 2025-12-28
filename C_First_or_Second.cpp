/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    int ans = INT_MIN;
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    vector<int> psum(n,0);
    psum[0] = a[0];

    for(int i = 1;i < n; i++) psum[i] = psum[i-1] + abs(a[i]);

    vector<int> ssum(n,0);
    ssum[n-1] = -a[n-1];

    for(int i = n-2; i >= 0; i--){
        ssum[i] = ssum[i+1] - a[i];
    }

    for(int x = 0; x < n; x++){
        if(x == 0){
            ans = max(ans,ssum[x+1]);
        }
        else if(x == n-1){
            ans = max(ans,psum[x-1]);
        }
        else{
            ans = max(ans,psum[x-1] + ssum[x+1]);
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
