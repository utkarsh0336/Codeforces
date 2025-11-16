/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    char ch = s[n-1];

    for(int i = n-2; i >= 0; i--){
        if(s[i] == ch) continue;
        cnt++;
    }

    cout<<cnt<<endl;
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
