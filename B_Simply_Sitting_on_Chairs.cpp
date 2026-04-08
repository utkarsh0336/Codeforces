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
// int t[200001][2];

int solve(int i,vector<int> &p,unordered_set<int> &st){
    // bool present = st.count(i+1) != 0;
    if(i == p.size() || st.count(i+1)) return 0;
    // if(t[i][present] != -1) return t[i][present];

    st.insert(p[i]);
    int take = 1 + solve(i+1,p,st);
    st.erase(p[i]);
    int skip = solve(i+1,p,st);

    return max(take,skip);

}

void Solve() {
    // your logic
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0;i < n; i++) cin >> p[i];

    // memset(t,-1,sizeof(t));

    unordered_set<int> st;
    int ans = solve(0,p,st);

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


