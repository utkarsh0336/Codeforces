/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    sort(begin(a),end(a));

    int i = -1, j = n - 1,team_size = 1,teams = 0;
    
    while(i < j){
        if(a[j] * team_size <= d && i < j){
            i++;
            team_size++;
        }
        else{
            teams++;
            j--;
            team_size = 1;
        }
    }

    cout<<teams<<endl;
    
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
