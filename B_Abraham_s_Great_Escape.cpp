/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,k;
    cin >> n >> k;

    vector<vector<char>> grid(n,vector<char>(n,'$'));
    int K = k;
    if(n*n == k){
        cout<<"YES"<<endl;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<'U';
            }
            cout<<endl;
        }
        return;
    }
    if(n*n - 1 <= k){
        cout<<"NO"<<endl;
        return;
    }
    for(int i = 0;i < n && k > 0; i++){
        for(int j = 0;j < n && k > 0; j++){
            grid[i][j] = 'U';
            k--;
        }
    }

    int r = (K-1) / n;

    if(r < n-1){
        for(int j = 0;j < n; j++){
            if(grid[r][j] == '$') grid[r][j] = 'D';
        }
    }

    for(int i = 0;i < n; i++){
        if(grid[i][0] == '$'){
            grid[i][0] = 'R';
        }
        if(grid[i][n-1] == '$'){
            grid[i][n-1] = 'L';
        }
    }

    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            if(grid[i][j] == '$') grid[i][j] = 'R';
        }
    }
    
    cout<<"YES"<<endl;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
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
