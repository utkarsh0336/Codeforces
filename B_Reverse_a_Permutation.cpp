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
    unordered_map<int,int> mp;

    for(int i = 0;i < n; i++){
        cin >> a[i];

        mp[a[i]] = i;
    }

    vector<int> temp = a;

    sort(begin(temp),end(temp),greater<int>());
    int l = n, r = -1;

    for(int i = 0;i < n; i++){
        if(temp[i] != a[i]){
            l = i;
            r = mp[temp[i]];
            break;
        }
    }

    if(l != n){
        reverse(begin(a) + l,begin(a) + r + 1);
    }

    for(int i = 0;i < n; i++) cout<<a[i]<<" ";
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
