/* Utkarsh Sahay */
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return (n == 2);
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void Solve() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << 1 << " " << n - 1 << "\n";
        return;
    }

    int best = 1; // largest divisor found
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int d1 = i, d2 = n / i;
            best = max(best, d1);
            best = max(best, d2); // take the larger divisor < n
        }
    }

    cout << best << " " << (n - best) << "\n";
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
