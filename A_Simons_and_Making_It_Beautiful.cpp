/* Utkarsh Sahay */

#include <iostream>
#include <vector>
using namespace std;

#define int long long

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int idx = 0;

    // Read input and find index of n
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) {
            idx = i;
        }
    }

    // Swap first element with element equal to n
    swap(a[0], a[idx]);

    // Print result
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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