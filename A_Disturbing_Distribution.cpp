/* Utkarsh Sahay */

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

const int MOD = 676767677;

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > 1) {
            sum += a[i];
        }
    }

    int ans = sum;

    if (a[n - 1] == 1) {
        ans += 1;
    }

    cout << ans % MOD << '\n';
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