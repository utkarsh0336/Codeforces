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

    if(n <= 2){
        cout<<1<<endl;
        return;
    }
    
    int ans = 0;
    int prev = -1;
    
        if(s[0] == '0' && s[1] == '0'){
            s[1] = '1';
        }

        if(s[n-1] == '0' && s[n-2] == '0'){
            s[n-2] = '1';
        }
    
    for(int i = 0;i < n; i++){
        if(s[i] != '1'){
            if(i - prev >= 3){
                ans++;
                s[i] = '1';
                prev = i;
            }
        }
        else{
            ans++;
            prev = i;
        }
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
