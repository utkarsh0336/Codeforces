/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0;i < n; i++){
        cin >> a[i];
        if(a[i] == k) cnt++;
    }

    unordered_set<int> st(begin(a),end(a));

    int num_b_k = 0;
    for(int i = 0;i < k; i++){
        if(st.count(i) == 0) num_b_k++;
    }

    cout<<max(cnt,num_b_k)<<endl;
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
