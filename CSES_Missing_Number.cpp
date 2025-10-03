/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;

    unordered_set<int> st;
    for(int i = 0;i < n-1; i++){
        int num;
        cin >> num;
        st.insert(num);
    }

    for(int i = 1;i <= n; i++){
        if(st.count(i) == 0){
            cout<<i<<endl;
        }
    }
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}