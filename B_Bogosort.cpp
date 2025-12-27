/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    sort(begin(a),end(a),greater<int>());

    for(int i = 0;i < n; i++) cout << a[i] << " ";
    cout<<endl;

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
