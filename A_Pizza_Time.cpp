/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
  int n;
  cin >> n;

  int ans = 0;
  while(n >= 3){
    int m1 = n / 3;
    ans += m1;

    n = (n - (2 * m1));  // m3 becomes n which is carried over to the next day.

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
