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
    int n,q; 
    cin >> n >> q;

    vector<int> a(n),b(n);

    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < n; i++) cin >> b[i];

    vector<int> bMax(n);
    bMax[n-1] = b[n-1];

    for(int i = n-2;i >= 0; i--){
        bMax[i] = max(bMax[i+1],b[i]);
    }
    while(q--){
        int l,r;
        cin >> l >> r;

        int ans = 0;
        for(int i = l-1;i < r; i++){
            ans += max(a[i],bMax[i]);
        }

        cout<<ans<<" ";
    }
    cout<<endl;
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
