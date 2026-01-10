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

void mex(vector<int> &a){
    unordered_set<int> st(begin(a),end(a));
    for(int i = 0;i < 2e5+1; i++){
        if(st.count(i) == 0){
            cout<<i<<endl;
            break;
        }
    }
}

void Solve() {
    // your logic
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(n == k){
        mex(a);
        return;
    }

    
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
