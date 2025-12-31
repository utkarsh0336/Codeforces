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

    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        st.insert(num);
    }

    int x = st.size();
    int ans = LLONG_MAX;

    for (auto it : st) {
        if (it >= x) ans = min(ans, it);
    }

    if (ans == LLONG_MAX) ans = -1;
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