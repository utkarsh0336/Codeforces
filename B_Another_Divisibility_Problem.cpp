/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

static int P10[11];
static vector<int> divisors[11];

void precomputeDivisors() {
    for (int d = 1; d <= 9; d++) {
        int num = P10[d] - 1;
        for (int i = 1; (int64_t)i * i <= num; i++) {
            if (num % i == 0) {
                divisors[d].push_back(i);
                if (i != num / i) divisors[d].push_back(num / i);
            }
        }
    }
}

void Solve(){
    int x;
    cin >> x;

    const int Y_MAX = 1000000000; // 1e9
    int answer = -1;

    for(int d = 1; d <= 9 && answer == -1; d++){
        for(int m : divisors[d]){
            int S = m * x;
            if(S > x){
                int y = S - x;
                if(y >= P10[d-1] && y <= P10[d]-1 && y < Y_MAX){
                    answer = y;
                    break;
                }
            }
        }
    }

    if(answer == -1) answer = 1;
    cout << answer << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    P10[0] = 1;
    for(int i = 1; i <= 10; i++) P10[i] = P10[i-1] * 10;

    precomputeDivisors();

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
