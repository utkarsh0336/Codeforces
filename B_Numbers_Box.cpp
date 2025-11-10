/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    int neg = 0;
    int sum = 0;
    int mini = INT_MAX;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < m; j++){
            cin >> a[i][j];
            if(a[i][j] < 0) neg++;
            sum += abs(a[i][j]); 
            mini = min(mini,abs(a[i][j]));
        }
    }

    if(neg % 2 == 0) cout<<sum<<endl;
    else cout<<sum - (2*mini)<<endl;

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
