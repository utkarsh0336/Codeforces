/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void Solve(){
    ll x , n;
    cin >> x >> n;

    ll ans = 0;
    if(n % 4 == 0){
        ans = 0;
    }
    else if(n % 4 == 1){
        ans = -n;
    }
    else if(n % 4 == 2){
        ans = 1;
    }
    else if(n % 4 == 3){
        ans = n+1;
    }

    if(x % 2){
        ans = x - ans;
    }
    else ans = x + ans;

    cout<<ans<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}