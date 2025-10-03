/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;
    vector<long long> a(n);   
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(begin(a), end(a));

    long long ans = 0;        

    for(int i = n-1; i >= 0; i -= 2){
        if(i == 0) ans += a[i];
        else ans += a[i];     
    }
    cout << ans << "\n";
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
