/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;

    int tot = n * (n + 1) / 2;
    

    if(tot % 2){
        cout<<"NO"<<endl;
        return;
    }
    
    unordered_set<int> st;
    int tar = tot / 2;

    int sum = 0;
    for(int i = n; sum < tar; i--){
        sum += i;
        st.insert(i);
        if(sum == tar) break;
        if(sum > tar){
            sum -= i;
            st.erase(i);
            break;
        }
    }

    int rem = tar - sum;
    if(rem != 0) st.insert(rem);

    cout<<"YES"<<endl;
    cout<<st.size()<<endl;
    for(auto it : st) cout<<it<<" ";
    cout<<endl;

    cout<<n - st.size()<<endl;

    for(int i = 1;i <= n; i++){
        if(st.count(i) == 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
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
