#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n % 2 == 1 || n < 4) {
            cout << -1 << "\n";
            continue;
        }

        long long min_buses = (n + 5) / 6; // ceil(n / 6.0)
        long long max_buses = n / 4;
        cout << min_buses << " " << max_buses << "\n";
    }

    return 0;
}
