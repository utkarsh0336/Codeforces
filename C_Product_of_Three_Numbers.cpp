/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
void Solve(){
    int n;
    cin >> n;

    int a = 1, b = 1, c = 1;
    for(int i = 2; i * i < n; i++){
        if(n % i == 0){
            a = i;
            break;
        }
    }

    n /= a;

    for(int i = 2;i * i < n; i++){
        if(a != i && n % i == 0){
            b = i;
            break;
        }
    }

    c = n / b;

    if(a != 1 && b != 1 && c != 1 && a != b && b != c && c != a){
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    else{
        cout<<"NO"<<endl;
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