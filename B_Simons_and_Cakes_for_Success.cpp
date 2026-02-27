#include <iostream>
using namespace std;

#define int long long

int solve(int n) {
    int k = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            k *= i;   // multiply distinct prime once
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // If remaining n is a prime
    if (n > 1) {
        k *= n;
    }

    return k;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}