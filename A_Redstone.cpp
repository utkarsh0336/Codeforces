/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    unordered_set<int> seen;
    bool ok = false;
    for(int x : a){
        if(seen.count(x)) ok = true;
        seen.insert(x);
    }

    cout << (ok ? "YES" : "NO") << "\n";
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
