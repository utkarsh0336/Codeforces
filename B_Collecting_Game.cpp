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

int bs(int ele,vector<int> &psum,vector<int> &a){
    int l = 0;
    int h = psum.size() - 1;
    int ans = -1;

    while(l <= h){
        int mid = l + (h - l) / 2;

        if(psum[mid] + a[mid]  >= ele){
            ans = mid;
            h = mid - 1;
        } 
        else{
            l = mid + 1;
        }
    }

    return ans;
}

void Solve() {
    // your logic
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    vector<int> temp = a;
    vector<int> psum(n,0);
    sort(begin(a),end(a));
    psum[0] = a[0];

    for(int i = 1;i < n; i++) psum[i] = psum[i-1] + a[i];

    vector<int> res;

    for(int i = 0;i < n; i++){
        int ele = temp[i];
        int idx = bs(ele,psum,a);
        res.push_back(idx);
    }

    for(auto ans : res) cout<<ans<<" ";
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
