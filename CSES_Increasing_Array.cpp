/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;

    for(int i = 1;i < n; i++){
        if(a[i-1] > a[i]){
            ans += abs(a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }

    cout<<ans<<endl;

}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}