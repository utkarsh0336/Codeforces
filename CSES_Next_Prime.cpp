/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(1e12+10,true);

void SOE(vector<bool> &isPrime){
    isPrime[0] = isPrime[1] = false;

    for(int i = 2;i * i < 1e12 + 10; i++){
        if(isPrime[i]){
            for(int j = i*i ; j < 1e12 + 10; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void Solve(){
    int n;
    cin >> n;

    bool found = false;

    for(int i = n+1;found == false; i++){
        if(isPrime[i]){
            found = true;
            cout<<i<<endl;
        }
    }

}
 
int main(){

    int t;
    cin >> t;

    SOE(isPrime);

    while(t--){
        Solve();
    }
 
    return 0;
}