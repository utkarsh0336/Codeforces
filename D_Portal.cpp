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
    int n,x,y;
    cin >> n >> x >> y;

    vector<int> left,right,mid,ans(n);

    for(int i = 0;i < n; i++){
        if(i >= x && i < y) mid.push_back(a[i]);
        else left.push_back(a[i]);
    }

    sort(begin(left),end(left));
    sort(begin(mid),end(mid));

    

    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
