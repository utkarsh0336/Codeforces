/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve(){
    ll n;
    cin >> n;
    vector<ll> vec;

    for (int k = 1; k <= 18; k++) {
        ll num = 1;
        for (int i = 0; i < k; i++) num *= 10; 
        num += 1; 

        if (num > n) break;
        if (n % num == 0) {
            ll x = n / num;  
            vec.push_back(x);
        }
    }

    if (vec.empty()) {
        cout << 0 << "\n";
        return;
    }

    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (ll x : vec) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
