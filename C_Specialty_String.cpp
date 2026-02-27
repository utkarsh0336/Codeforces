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

    stack<char> st;
    for(int i = 0;i < n; i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
    }

    if(st.empty()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
