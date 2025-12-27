/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int a,b;
    cin >> a >> b;

    int x = 0,y = 0;
    int ra,rb;

    while(a % 2 == 0){
        x++;
        a /= 2;
    }
    ra = a;

    while(b % 2 == 0){
        y++;
        b /= 2;
    }
    rb = b;

    if(ra != rb){
        cout<<-1<<endl;
    }
    else{
        cout<<(abs(x - y) / 3) + (abs(x - y) % 3 != 0)<<endl;
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
