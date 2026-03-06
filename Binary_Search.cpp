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
    for(int i = 0;i < n; i++) cin >> a[i];
    int tar = 3;

    int l = 0, h = n-1;
    while(l < h){
        int mid = l + (h - l) / 2;
        if(a[mid] < tar){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }

    cout<<"Found Hurray !!"<<endl;
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
