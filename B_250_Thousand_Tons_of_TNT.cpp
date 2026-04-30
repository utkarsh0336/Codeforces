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
    for(int i = 0; i < n; i++) cin >> a[i];

    // int ans = (*max_element(begin(a),end(a))) - (*min_element(begin(a),end(a)));
    int ans = 0;
    vector<int> psum(n);
    psum[0] = a[0];

    for(int i = 1; i < n; i++){
        psum[i] = psum[i-1] + a[i];
    }
    
    
    for(int k = 1;k <= n; k++){
        int maxi = psum[k-1], mini = psum[k-1], start = k-1;
        if(n % k == 0){
            for(int i = k + start;i < n; i += k){
                maxi = max(maxi,psum[i] - psum[i-k]);
                mini = min(mini,psum[i] - psum[i-k]);

            }
            // ans = max(ans,psum[i] - psum[i-k]);

            ans = max(ans,maxi - mini);
        }
    }
    
    // int sum = accumulate(begin(a),end(a),0);
    // ans = max(ans,sum);
    cout<<ans<<endl;
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
