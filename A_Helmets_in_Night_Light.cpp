/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
 
void Solve(){
    int n,p;
    cin >> n >> p;
    vector<int> a(n),b(n);

    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    for(int i = 0;i < n; i++){
        cin >> b[i];
    }

    priority_queue<P,vector<P>,greater<P>> pq;

    for(int i = 0;i < n; i++){
        pq.push({b[i],-a[i]});
    }

    int ans = p;
    int cnt = 1;

    while(cnt < n && !pq.empty()){
        int cost = pq.top().first;
        int num = pq.top().second * -1;
        pq.pop();

        if(cost > p){
            ans += p;
            cnt++;
        }
        else{
            ans += (cost * min(num,n - cnt));
            cnt += num;
        }
    }
    
    cout<<ans<<endl;
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