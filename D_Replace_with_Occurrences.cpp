/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void Solve(){
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    unordered_map<int,int> mp,mp1;
    for(int num : b) mp[num]++;

    int sum = 0;
    for(auto it : mp) sum += it.second;
    if(sum > n){
        cout<<-1<<endl;
        return;
    }

    vector<int> ans(n);
    for(int i = 0;i < n; i++){
        int num = b[i];
        int ele = 1;
        while(num--){
            ans.push_back(ele);
        }
        ele++;
    }
    for(auto a : ans) cout<<a<<" ";


}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}