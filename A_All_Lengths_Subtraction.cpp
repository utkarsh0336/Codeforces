/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0;i < n ; i++) cin >> a[i];

    int peak = 0;
    bool neg = false;
    for(int i = 1; i < n-1; i++){
        if(a[i] > a[i+1] && a[i] > a[i-1]){
            peak++;
        }
        else if(a[i] < a[i+1] && a[i] < a[i-1]){
            neg = true;
            break;
        }
    }

    if(peak <= 1 && neg == false){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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
