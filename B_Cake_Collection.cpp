/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end(), greater<int>());
    
    int k = min<int>(n, m);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += a[i] * (m - i);
    }
    
    cout << ans << "\n";
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
