/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int a , b;
    cin >> a >> b;

    if(a == b){
        cout<<0<<endl;
        return;
    }
    if(a == 1 || b == 1){
        cout<<1<<endl;
        return;
    }
    int mini = min(a,b);
    int maxi = max(a,b);

    if(maxi % mini == 0){
        cout<<1<<endl;
        return;
    }
    cout<<2<<endl;
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