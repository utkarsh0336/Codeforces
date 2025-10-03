/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,k,b,s;
    cin >> n >> k >> b >> s;

    int minsum = b * k;
    int maxsum = minsum + (n * (k-1));

    if(minsum > s || maxsum < s){
        cout<<-1<<endl;
        return;
    }

    vector<int> a(n);
    a[0] = minsum;
    int rem = s - minsum;
    for(int i = 0;i < n ; i++){
        a[i] += (rem >= k) ? (k-1) : (rem > 0) ? rem : 0;
        rem -= (k-1);
        cout<<a[i]<<" ";
    }
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
