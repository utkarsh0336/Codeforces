/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    long long sum = 0, maxBeauty = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        maxBeauty += (a[i] + x - 1) / x;
    }

    long long minBeauty = (sum + x - 1) / x; // ceil(sum/x)

    cout << minBeauty << " " << maxBeauty << "\n";
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
