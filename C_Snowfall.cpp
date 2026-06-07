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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, unordered_map<int, int>> mp;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        if (a[i] % 6 == 0) {
            mp[6][a[i]]++;
        }
        else if (a[i] % 2 == 0) {
            mp[2][a[i]]++;
        }
        else if (a[i] % 3 == 0) {
            mp[3][a[i]]++;
        }
        else {
            mp[9][a[i]]++;
        }
    }

    int idx = 0;

    for (auto it : mp[6]) {
        int value = it.first;
        int freq = it.second;

        while (freq--) {
            ans[idx++] = value;
        }
    }

    for (auto it : mp[2]) {
        int value = it.first;
        int freq = it.second;

        while (freq--) {
            ans[idx++] = value;
        }
    }

    int lIdx = idx;

    idx = n - 1;

    for (auto it : mp[3]) {
        int value = it.first;
        int freq = it.second;

        while (freq--) {
            ans[idx--] = value;
        }
    }

    for (auto it : mp[9]) {
        int value = it.first;
        int freq = it.second;

        while (freq--) {
            ans[lIdx++] = value;
        }
    }

    for (auto res : ans) {
        cout << res << " ";
    }

    cout << endl;
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
