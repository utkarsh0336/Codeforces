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

    vector<int> ans(3*n,-1);
    int num = n + 1;

    for(int i = 1;i < 3*n; i += 3){
        ans[i] = num;
        num += 2;
    }

    for(int i = 1; i < 3*n; i += 3){
        int ele = ans[i];
        ans[i+1] = ele + 1;
    }

    int cnt = 1;
    for(int i = 3*n - 1; i >= 0; i--){
        if(ans[i] == -1){
            ans[i] = cnt;
            cnt++;
        }
    }

    for(auto a : ans) cout<<a<<" ";
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
