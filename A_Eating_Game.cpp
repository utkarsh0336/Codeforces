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
    // your logic
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = 0;
    
    for(int i = 0;i < n; i++) cin >> a[i];

    unordered_map<int,int> mp;
    for(int i = 0;i < n; i++){
        mp[a[i]]++;
        maxi = max(maxi,a[i]);
    }

    cout<<mp[maxi]<<endl;
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
