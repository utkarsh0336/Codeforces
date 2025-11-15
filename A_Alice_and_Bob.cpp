/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    int a;
    cin >> a;

    vector<int> vec(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    cout<<a+1<<endl;
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
