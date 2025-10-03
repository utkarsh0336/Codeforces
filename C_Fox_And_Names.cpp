/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int m;
    cin >> m;
    string b,c;
    cin >> b >> c;

    for(int i = 0;i < c.size(); i++){
        if(c[i] == 'D'){
            a = a + b[i];
        }
        else{
            a = b[i] + a;
        }
    }

    cout<<a<<endl;
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}