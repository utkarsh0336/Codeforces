/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long pow3(long long exp) {
    long long base = 3;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;   
        base *= base;                  
        exp >>= 1;                     
    }
    return result;
}

ll calc(ll x){
    ll a = pow3(x+1);
    ll b = x * pow3(x-1);

    return a + b;
}

string triplet(long long n) {
    if (n == 0) return "0";
    string ans = "";
    while (n > 0) {
        int dig = n % 3;
        ans.push_back('0' + dig); 
        n /= 3;
    }
    reverse(ans.begin(), ans.end()); 
    return ans;
}


void Solve(){
    ll n;
    cin >> n;
    ll ans = 0;

    string str = triplet(n);
    for(int i = 0;i < str.size(); i++){
        ans += ((str[i] - '0') * (calc(str.size()-i-1)));
    }
    cout<<ans<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}