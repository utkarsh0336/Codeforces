/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long


void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    vector<int> o,e;

    for(auto num : a){
        if(num % 2 == 0) e.push_back(num);
        else o.push_back(num);
    }

    if(e.empty()){
        for(int num : a) cout<<num<<" ";
        cout<<endl;
        return;
    }

    if(o.empty()){
        for(int num : a) cout<<num<<" ";
        cout<<endl;
        return;
    }
    
    sort(begin(a),end(a));
    for(int i = 0;i < n; i++) cout << a[i]<<" ";
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
