/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> q(n);

    for(int i = 0;i < n; i++){
        cout<<n + 1 - p[i]<<" ";
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}