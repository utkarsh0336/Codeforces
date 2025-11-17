/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define N 1000001
vector<int> spf(N);

void Solve(){
    int n;
    cin >> n;

    for(int i = 1;i < N; i++) spf[i] = i;

    // spf is smallest prime factor of i i.e spf[i]

    for(int i = 2;i * i <= n; i++){
        if(spf[i] != i) continue;

        for(int j = i * i; j <= n; j += i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }

    cout<<spf[30];
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
