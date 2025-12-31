/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool chk(string &s){
    bool op1 = false;
    bool op2 = true;

    string st = "";
    for(int i = 0;i < s.size(); i++){
        if(st.size() < 4){
            st += s[i];
        }
        else{
            if(st == "2026"){
                op1 = true;
                st = "";
                break;
            }
            else if(st == "2025"){
                op2 = false;
                st = s[i];
                // break;
            }
            else{
                st = s[i];
            }
        }
    }

    if(!st.empty()){
        if(st.size() == 4){
            return st == "2026" || st != "2025";
        }
    }

    return op1 || op2;
}

void Solve(){
    int n;
    cin >> n;
    string s; 
    cin >> s;

    bool ch = chk(s);
    if(ch){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
    }
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
