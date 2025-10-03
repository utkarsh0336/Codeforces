/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    long long n,k;
    cin >> n >> k;
    vector<long long> a(n*k);
    for(int i = 0;i < n*k; i++) cin >> a[i];

    long long pointer = n*k;
    long long sum = 0;

    while(k--){
        pointer -= (n / 2 + 1);
        sum += a[pointer];
    }

    cout<<sum<<endl;

}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}