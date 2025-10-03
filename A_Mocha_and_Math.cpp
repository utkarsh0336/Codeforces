/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n; 
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    int ans = a[0];
    for(int i = 1;i < n; i++) ans = (ans & a[i]);
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