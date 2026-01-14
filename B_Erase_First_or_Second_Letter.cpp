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

    string s;
    cin >> s;
    
    unordered_set<char> st;
    // vector<int> distinct(n);

    // distinct[0] = 1;
    int cnt = 1;
    st.insert(s[0]);

    int ans = 1;

    for(int i = 1;i < n; i++){
        char ch = s[i];
        if(st.count(ch) == 0){
            cnt++;
            st.insert(ch);
        }
        // else{
        //     distinct[i] = distinct[i-1];
        // }
        ans += cnt;
    }

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
