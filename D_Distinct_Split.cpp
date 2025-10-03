/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;

    vector<int> pre(n),suf(n);

    unordered_set<char> st;
    string stl = "";
    for(int i = 0;i < n; i++){
        st.insert(s[i]);
        // unordered_set<char> st(begin(stl),end(stl));
        pre[i] = st.size();
    }

    st.clear();
    // string str = "";
    for(int i = n-1;i >= 0; i--){
        // str += s[i];
        st.insert(s[i]);
        suf[i] = st.size();
    }
    
    // for(int i = 0;i < n; i++) cout<<pre[i]<<" ";
    // cout<<endl;
    // for(int i = 0;i < n; i++) cout<<suf[i]<<" ";
    
    for(int i = 0;i < n-1; i++){
        ans = max(ans,pre[i] + suf[i+1]);
    }

    cout<<ans<<endl;

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