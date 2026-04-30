/* Utkarsh Sahay */

// Portable replacement for bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <cstring>
#include <string>
#include <limits>
#include <climits>

using namespace std;

#define int long long

void Solve() {
    int n;
    cin >> n;

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int ans = 0;

    // A good subarray can only have length 2.
    // So we only check adjacent pairs.
    for (int i = 0; i + 1 < n; i++) {
        int a = p[i];
        int b = p[i + 1];

        int diff = abs(a - b);
        int small = min(a, b);

        // For pair [a, b]:
        // max - min = diff
        // gcd(a, b) = diff only when diff divides the smaller number
        if (small % diff == 0) {
            ans++;
        }
    }

    cout << ans << '\n';
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