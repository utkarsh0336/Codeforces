/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0;i < n; i++) cin >> a[i];

    int sum = 0;

    for(int t : a){
        sum += t;
        if(sum <= 0){
            cout<<"NO"<<endl;
            return;
        }
    }

    sum = 0;

    for(int i = n-1 ; i >= 0 ; i--){
        sum += a[i];
        if(sum <= 0){
            cout<<"NO"<<endl;
            return;
        }
    }

   cout<<"YES"<<endl;
}
 
int32_t main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}