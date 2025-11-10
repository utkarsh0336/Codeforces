/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(char c: s){
        if(c == '0') cnt0++;
        else if(c == '1') cnt1++;
        else cnt2++;
    }

    int L = cnt0;           
    int R = cnt0 + cnt2;    

    string ans;
    ans.resize(n);

    for(int p = 1; p <= n; ++p){
        bool possibleRemoved = (p <= R) || (p >= (n - k + 1 + L));

        if(!possibleRemoved){
            ans[p-1] = '+';
            continue;
        }
        int LB = p - n + k;
        int UB = p - 1;

        int low = max((int)L, (int)LB);
        int high = min((int)R, (int)UB);

        if(low <= high){

            ans[p-1] = '?';
        } else {
            ans[p-1] = '-';
        }
    }

    cout << ans << '\n';
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
