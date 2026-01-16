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
    int n,k;
    cin >> n >> k;

    vector<int> a(n),b(n);

    for(int i = 0;i < n; i++) cin >> a[i];
    for(int i = 0;i < n; i++) cin >> b[i];

    int ans = a[0];
    int res = a[0];

    int max_in_b = b[0];

    for(int i = 1;i < min(n,k); i++){
        res = max(res,ans + (k - i) * max_in_b);

        ans += a[i];

        max_in_b = max(max_in_b,b[i]);
    }
    if(n < k){
        // max_in_b = max(max_in_b,b[n-1]);
        ans += (k - n) * max_in_b;
       cout<<max(ans,res)<<endl;
        return;
    }
    cout<<max(ans,res)<<endl;

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
