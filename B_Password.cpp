/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;

ll blackbox(string &s){
    ll ans = 0;
    ll p = 1;
    for(ll i = 0;i < s.size(); i++){
        ans = (ans + ((s[i] - 'a' + 1ll) * p) % mod) % mod;
        p = (p * 31ll) % mod;
    }
    return ans;
}

ll power(ll base, ll x){
    ll ans = 1;
    while(x){
        if(x % 2 == 0){
            base = (base * base) % mod;
            x /= 2;
        }
        else{
            ans = (ans * base) % mod;
            x--;
        }
    }
    return ans;
}

bool check(string &s, ll len){
    string p = s.substr(0,len);
    ll plen = len;
    ll slen = s.size();
    ll phash = blackbox(p);
    string temp = s.substr(0,plen);
    ll shash = blackbox(temp);
    ll cnt = 0;
    if(phash == shash) cnt++;
    ll prL = 1;
    ll prR = power(31,plen);
    for(ll i = plen; i < slen; i++){
        shash = (shash - ((s[i-plen] - 'a' + 1) * prL) % mod + mod) % mod;
        shash = (shash + ((s[i] - 'a' + 1) * prR) % mod) % mod;
        phash = (phash * 31) % mod;
        if(shash == phash) cnt++;
        prL = (prL * 31) % mod;
        prR = (prR * 31) % mod;

    }
    return (cnt > 2);
}
void Solve() {
    string s;
    cin >> s;

    ll n = s.size();
    ll hash = 0;
    ll p = 1;

    vector<ll> h(n);

    for(int i = 0;i < n; i++){
        hash = (hash + ((s[i] - 'a' + 1) * p) % mod ) % mod;
        p = (p * 31ll) % mod;
        h[i] = hash;
    }

    hash = 0;
    vector<ll> vec;
    for(int i = n-1; i >= 0; i--){
        hash = (hash * 31ll) % mod;
        hash = (hash + (s[i] - 'a' + 1)) % mod;
        if(hash == h[n-i-1]){
            vec.push_back(n-i-1);
        }
    }

    ll low = 0, high = vec.size() - 1;

    while(low <= high){
        ll mid = (low + high) >> 1;
        if(check(s,vec[mid] + 1)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    if(high < 0){
        cout<<"Just a legend"<<"\n";
    }
    else{
        cout<<s.substr(0,vec[high]+1)<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}
