/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 3; i+= 2){
        cout << "-1 3" << ' ';
    }
    if(n % 2 == 0){
        cout << "-1 2" << endl;
    }else{
        cout << "-1 3 -1" << endl;
    }
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}