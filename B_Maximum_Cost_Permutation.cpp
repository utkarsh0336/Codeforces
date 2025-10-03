/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    unordered_set<int> st(begin(a),end(a));

    int num = n;
    for(int i = 0;i < n; i++){
        if(a[i] == 0){
            bool done = false;
            while(!done && num > 0){
                if(st.count(num) == 0){
                    a[i] = num;
                    done = true;
                }
                num--;   
            }
        }
    }

    int l = -1 , r = -1;

    for(int i = 0;i < n; i++){
        if(a[i] != (i + 1)){
            l = i;
            break;
        }
    }

    for(int i = n-1; i >= 0; i--){
        if(a[i] != (i + 1)){
            r = i;
            break;
        }
    }

    if(l != -1 && r != -1)
        cout<<r - l + 1<<endl;
    else cout<<0<<endl;
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
