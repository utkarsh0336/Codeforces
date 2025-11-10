#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

int t;
cin >> t;
while (t--) {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x != 0) s.insert(x);
    }
    if (s.empty()) {
        cout << 0 << '\n';
    } else {
        ll D = (ll)s.size();
        cout << (2*D - 1) << '\n';
    }
}
return 0;

}
