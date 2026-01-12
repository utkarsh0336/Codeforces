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

// T.C :- 2^n * n (Number of possible states of bitmask * pos (index for city))


const int n = 4;  // if we write int n = 4 and then try to make int dp[1 << n][n] then it gives error , we have to make const int n = 4 then only it will work
int dp[1 << n][n];
// Adj Matrix which defines our graph
int dist[10][10] = {{0,20,42,25},
                    {20,0,30,34},   // Output will be 85
                    {42,30,0,10},
                    {25,34,10,0}};



// If all cities have been visited
int VISITED_ALL = (1 << n) - 1;

int travellingSalesmanProblem(int mask,int pos){
    if(mask == VISITED_ALL){
        return dist[pos][0];
    }

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;

    // Try to goto an unvisited city
    for(int city = 0;city < n; city++){
        if((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + travellingSalesmanProblem(mask | (1 << city),city);
            ans = min(ans,newAns);
        }
    }

    return dp[mask][pos] = ans;
}

void Solve() {
    memset(dp,-1,sizeof(dp));
    cout<<travellingSalesmanProblem(1,0); // It is minimum weight hamiltonian path

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
