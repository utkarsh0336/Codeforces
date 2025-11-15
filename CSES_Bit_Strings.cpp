/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;

long long binpow(long long n) {
    long long ans = 1;
    long long base = 2;   // because we are computing 2^n

    while (n > 0) {
        if (n & 1) {  
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;   // square the base
        n >>= 1;                      // divide n by 2
    }
    return ans;
}

void Solve(){
    int n;
    cin >> n;

    cout<<(binpow(n) % mod)<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}
