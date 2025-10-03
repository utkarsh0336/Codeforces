/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
bool check(vector<int> &a,int mid,int t){
    int cnt = 0;
    for(int i = 0;i < a.size(); i++){
        cnt += (mid / a[i]);
    }
    return cnt >= t;
}
 
void Solve(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    int mini = *min_element(begin(a),end(a));

    int l = 0;
    int h = t * mini;
    int ans = -1;
 
    while(l <= h){
        int mid = l + (h - l) / 2;
        if(check(a,mid,t)){
            ans = mid;
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
 
    cout<<ans<<endl;
 
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}
