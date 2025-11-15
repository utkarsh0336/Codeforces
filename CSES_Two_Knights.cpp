/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n){
    if(n == 1) return 0;
    int tot = n * n;
    int total_pos = (tot * (tot-1)) / 2;

    return total_pos - 4 * (n - 1) * (n - 2);
}

void Solve(){
    int n;
    cin >> n;
    
    for(int i = 1;i <=n; i++){
        cout<<solve(i)<<endl;
    }

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
