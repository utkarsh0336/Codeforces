/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    unordered_set<int> st;
    for(int i = 0;i < n; i++){
        int a;
        cin >> a;
        st.insert(a);
    }
    int mex = 0;
    while(st.count(mex)){
        mex++;
    }
    cout<<mex<<endl;
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
