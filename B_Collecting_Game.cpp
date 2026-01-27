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
    vector<pair<int,int>> a(n);

    for(int i = 0;i < n; i++){
        pair<int,int> p = {a[i],i};
        a.push_back(p);
    }
    sort(begin(a),end(a));
    vector<int> psum(n);
    psum[0] = a[0].first;

    for(int i = 1;i < n; i++) psum[i] = psum[i-1] + a[i].first;

    vector<int> res(n);
    int score = 0;

    for(int i = 0;i < n; i++){
        int ele = a[i].first;
        int idx = a[i].second;

        score += psum[i];
        
        auto lb = lower_bound(begin(psum),end(psum),score+1);
        int ans = lb - begin(psum);
        res[idx] = ans;
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
