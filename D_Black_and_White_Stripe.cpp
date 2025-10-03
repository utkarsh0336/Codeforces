/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    int i = 0, j = 0;
    int ans = INT_MAX;
    int cntw = 0, cntb = 0;

    while(j < n){
        while(j - i + 1 > k){
            if(s[i] == 'B') cntb--;
            if(s[i] == 'W') cntw--;
            i++;
        }
        if(s[j] == 'B') cntb++;
        if(s[j] == 'W') cntw++;
        if(j-i+1 == k)
            ans = min(ans,cntw);
        j++;
    }
    ans = min(ans,cntw);
    cout<<ans<<endl;
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
