/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    int k;
    cin >> n >> k;

    vector<int> a(n),b(k);
    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < k; i++) cin >> b[i];

    sort(begin(a),end(a));
    sort(begin(b),end(b));

    int i = n-1 , j = 0;

    int cost = 0;
    while(i >= 0){
        if(b[j] == 1){
            i--;
        }
        else{
            int it = b[j] - 1;
            while(it-- && i >= 0){
                cost += a[i];
                i--;
            }
            i--;
        }
        j++;
    }

    cout<<cost<<endl;
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
