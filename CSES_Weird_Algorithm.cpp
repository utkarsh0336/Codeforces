/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Solve(){
    ll n;
    cin >> n;
    cout<<n<<" ";
    while(n != 1){
        if(n % 2){
            n = (n * 3) + 1;
            cout<<n<<" ";
        }
        else{
            n /= 2;
            cout<<n<<" ";
        }
    }
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}