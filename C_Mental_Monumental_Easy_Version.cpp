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

bool canMakeMex(int k, vector<int>& a, vector<int>& freq) {
    int n = a.size();

    vector<int> missing;

    // Find values from 0 to k - 1 which are not present directly
    for (int x = 0; x < k; x++) {
        if (freq[x] == 0) {
            missing.push_back(x);
        }
    }

    // usedExact[x] means we have already reserved one element equal to x
    vector<int> usedExact(k, 0);

    vector<int> capacity;

    for (int val : a) {
        // If val is needed directly for MEX and we have not reserved it yet,
        // reserve one occurrence of val for itself.
        if (val < k && usedExact[val] == 0) {
            usedExact[val] = 1;
        } 
        else {
            // Remaining elements can be used to create smaller values.
            // val can create all x such that val > 2 * x
            // So max x = (val - 1) / 2
            if (val > 0) {
                capacity.push_back((val - 1) / 2);
            }
        }
    }

    // a is sorted, so capacity is already sorted,
    // but sorting again is safe.
    sort(capacity.begin(), capacity.end());

    int j = 0;

    // Assign each missing value to the smallest possible remaining element
    for (int x : missing) {
        while (j < capacity.size() && capacity[j] < x) {
            j++;
        }

        if (j == capacity.size()) {
            return false;
        }

        j++;
    }

    return true;
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }

    sort(a.begin(), a.end());

    vector<int> freq(max(maxVal + 1, n + 1), 0);

    for (int x : a) {
        freq[x]++;
    }

    int low = 0;
    int high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canMakeMex(mid, a, freq)) {
            ans = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
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