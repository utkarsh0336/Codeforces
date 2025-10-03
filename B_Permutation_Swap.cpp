/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i <n; i++) cin >> a[i];

    int ans = 0;
    unordered_set<int> st;
    for(int i = 0;i < n/2; i++){
        if(st.count(a[i]) == 0){
            ans = max(ans,abs(a[i] - (i+1)));
            st.insert(a[i]);
            st.insert(i+1);
        }
    } 

    cout<<ans<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}