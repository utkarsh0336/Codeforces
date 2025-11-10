/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    unordered_set<int> st;
    bool found = false;
    for(int i = 0;i < n; i++){
        int b;
        cin >> b;
        if(st.count(b)){
            found = true;
        }
        st.insert(b);
    }
    if(found) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
