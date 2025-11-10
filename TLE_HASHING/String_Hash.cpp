#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 1e9+ 7;

ll get_hash(string s){
  ll h = 0;
  for(auto c : s){
    h = (h * 31 + (c - 'a' + 1)) % mod ;
  }
  return h;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll hash = get_hash("ab");
    cout<<hash<<endl;

    
    return 0;
}