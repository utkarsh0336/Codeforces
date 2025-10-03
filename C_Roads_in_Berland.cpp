/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<vector<int>> dist(n+1,vector<int>(n+1,0));

    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= n; j++){
            cin >> dist[i][j];
        }
    }

    int k;
    cin >> k;

    for(int q = 0;q < k; q++){
        int a , b , wt;
        cin >> a >> b >> wt;

        dist[a][b] = dist[b][a] = min(wt,dist[a][b]);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1;j <= n; j++){
                dist[i][j] = min(dist[i][j] , 
                dist[i][a] + wt + dist[b][j]);
                
                dist[i][j] = min(dist[i][j],
                dist[i][b] + wt + dist[a][j]);
                ans += dist[i][j];
            }
        }
        cout<<ans/2<<" ";
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
