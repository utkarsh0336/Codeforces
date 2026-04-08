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

    if(n == 1){
        cout<<3<<endl;
        return;
    }
    if(n == 2){
        cout<<3<<" "<<3<<endl;
        return;
    }

    vector<int> ans(n,1);

    ans[0] = 3;
    ans[1] = 3;

    int num = 5;
    for(int i = 2;i < n; i++){
        ans[i] = num * ans[i-1];
        num += 2;
    }

    for(int a : ans) cout<<a<<" ";
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
