/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define N 1000001
vector<bool> isPrime(N,true);

void Solve(){
    int n;
    cin >> n;

    for(int i = 2;i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }

    if(isPrime[n]) cout<<"Prime"<<endl;
    else cout<<"Not a Prime"<<endl;
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
