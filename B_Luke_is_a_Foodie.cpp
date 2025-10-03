/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n , x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    int v = 0;
    vector<vector<int>> intervals;

    for(int i = 0;i < n; i++){
        int l = a[i] - x;
        int r = a[i] + x;
        intervals.push_back({l,r});
    }

    auto vec = intervals[0];
    int l = vec[0];
    int r = vec[1];
    for(int i = 1;i < intervals.size(); i++){

        l = max(l,intervals[i][0]);
        r = min(r,intervals[i][1]);

        if(l > r){
            v++;
            l = intervals[i][0];
            r = intervals[i][1];
        }
    }

    cout<<v<<endl;
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
