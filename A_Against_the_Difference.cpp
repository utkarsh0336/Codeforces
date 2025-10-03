#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n; i++) cin >> a[i];

        unordered_map<int,int> mp;
        for(auto k : a) mp[k]++;

        ll ans = 0;
        for(auto it : mp){
            if(it.first == 1) ans += mp[1];
            else if(it.second >= it.first){
                ans += min(it.first,it.second);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
