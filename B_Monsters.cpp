/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; // smaller second comes first
        }
        return a.first < b.first; // larger first comes first
    }
};
 
void Solve(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0;i < n; i++){
        int num;
        cin >> num;
        if(num > k)
            a[i] = (num % k == 0) ? k : num % k; 
        else a[i] = num;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

    for(int i = 0;i < n; i++){
        pq.push({a[i],i});
    }

    vector<int> ans;

    while(!pq.empty()){
        int h = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        ans.push_back(idx+1);
    }

    for(int q : ans) cout<<q<<" ";
    cout<<"\n";

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