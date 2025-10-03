/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;

    // vector<int> cells;
    // for(int i = 0;i < n; i++){
    //     if(s[i] == 'B') cells.push_back(i+1);
    // }

    unordered_set<int> blacks;
    vector<int> ans;
    for(int i = 0;i < m; i++){
        int b;
        cin >> b;
        blacks.insert(b);
    }

    int cnt = 0;
    int steps = 1;
    for(auto ch : s){
        if(ch == 'A'){
            steps++;
            blacks.insert(steps);
            cnt++;
            // ans.push_back(steps);
        }
        else{
            steps++;
            while(true){  
                if(blacks.count(steps) == 0){
                    blacks.insert(steps);
                    cnt++;
                    break;
                }
                steps++;
            }
            // ans.push_back(steps);
        }
    }

    cout<<blacks.size()<<endl;
    for(auto it : blacks) ans.push_back(it);
    sort(begin(ans),end(ans));
    for(int i = 0;i < ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
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
