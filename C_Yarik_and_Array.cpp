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

    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    int maxi = a[0], sum = a[0], res = a[0];

    for(int i = 1;i < n; i++){
        int curr = a[i];
        int prev = a[i-1];

        if(abs(curr) % 2 != abs(prev) % 2){
            sum = max(sum + a[i],a[i]);
            maxi = max(sum,maxi);
        }
        else{
            maxi = a[i];
            sum = a[i];
        }

        res = max(res,maxi);
    }

    cout<<res<<endl;
    
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
