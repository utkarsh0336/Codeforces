/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n < 3){
        cout << "0 0\n";
        return;
    }

    vector<int> pref(n+1, 0);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        pref[i] = sum % 3;
    }

    int total = pref[n] % 3;
    if(total != 0){
        cout << "0 0\n";
        return;
    }

    vector<vector<int>> pos(3);
    for(int r = 2; r <= n-1; r++){
        pos[pref[r]].push_back(r);
    }

    bool found = false;
    for(int l = 1; l <= n-2 && !found; l++){
        int s1 = pref[l];
        for(int v = 0; v < 3; v++){
            auto it = lower_bound(pos[v].begin(), pos[v].end(), l+1);
            if(it == pos[v].end()) continue;
            int r = *it;

            int s2 = (v - s1 + 3) % 3;
            int s3 = (total - v + 3) % 3; 

            if((s1 == s2 && s2 == s3) || (s1 != s2 && s1 != s3 && s2 != s3)){
                cout << l << " " << r << "\n";
                found = true;
                break;
            }
        }
    }

    if(!found) cout << "0 0\n";
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
