/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    char ch;
    cin >> ch;

    string st;
    cin >> st;

    if(ch == 'g'){
        cout<<0<<endl;
        return;
    }

    string s = st + st;
    int N = s.size();

    int i = 0, j = 0,ans = 0;

    while(i < N && j < N){
        while(i < N && j < N && s[i] != ch) i++;
        j = i + 1;
        while(i < N && j < N && s[j] != 'g') j++;
        ans = max(ans,j-i);
        i = j + 1;
    }

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
