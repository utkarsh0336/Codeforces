/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    sort(begin(a),end(a));
    int s = 0;
    int bp = 0;
    for(int i = 0;i < n; i++){
        s += a[i];

        if(s >= x){
            bp += (s / x);
        }
    }

    cout<<bp<<endl;
    for(int i : a) cout<<i<<" ";
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
