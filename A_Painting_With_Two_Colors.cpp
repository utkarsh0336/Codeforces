#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if(!(cin >> t)) return 0;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        if ((n % 2) != (b % 2)) {
            cout << "NO\n";
            continue;
        }
        if (a <= b) {
            cout << "YES\n";
            continue;
        }
        if ((a % 2) == (n % 2)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
