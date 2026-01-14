/* Utkarsh Sahay */

// Portable replacement for bits/stdc++.h
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <cstring>
#include <string>
#include <limits>
#include <climits>

using namespace std;

#define int long long

/*
    Input :- 
    3 3
    Rahul Ajay 100
    Ajay Neha 50
    Neha Rahul 40


    Output :- Should also show transactions 
    Rahul pays 50 to Ajay
    Rahul pays 10 to Neha
    2
*/

// class Person_Compare{
//     public:
//         bool operator()(pair<string,int> p1,pair<string,int> p2){
//             return p1.second < p2.second;
//         }
// };

class Person_Compare {
public:
    bool operator()(const pair<string,int>& p1,
                    const pair<string,int>& p2) const {
        return p1.second < p2.second;
    }
};



void Solve() {  
    int no_of_transactions,friends;
    cin >> no_of_transactions >> friends;

    map<string,int> net;
    
    string x,y;
    int amount;

    while(no_of_transactions--){

        cin >> x >> y >> amount;
        
        if(net.count(x) == 0) net[x] = 0;
        if(net.count(y) == 0) net[y] = 0;

        net[x] -= amount;
        net[y] += amount;
    }

    multiset<pair<string,int>,Person_Compare> st;
    
    for(auto it : net){
        string person = it.first;
        int amount = it.second;
        
        if(net[person] != 0){
          st.insert(make_pair(person,amount));
        }
    }

    int cnt = 0;  // count of transactions

    while(!st.empty()){
        auto low = st.begin();
        auto high = prev(st.end());
        
        int debit = low->second;
        string debit_person = low->first;

        int credit = high->second;
        string credit_person = high->first;
        
        
        // Pop them out
        st.erase(low);
        st.erase(high);

        int setteledAmount = min(-debit,credit);

        debit += setteledAmount;
        credit -= setteledAmount;

        cout<<debit_person<<" pays "<<setteledAmount<<" to "<<credit_person<<endl;

        if(debit != 0) st.insert(make_pair(debit_person,debit));
        if(credit != 0) st.insert(make_pair(credit_person,credit));

        cnt++;
    }

    cout<<cnt<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}















