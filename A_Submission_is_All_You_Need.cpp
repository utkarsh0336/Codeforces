#include <bits/stdc++.h>
using namespace std;

int get_max_score(vector<int>& S) {
    int freq[101] = {0};
    for (int x : S) freq[x]++;

    int mex = 0;
    vector<int> used; 
    while (freq[mex] > 0) {
        freq[mex]--;
        used.push_back(mex);
        mex++;
    }

    int score = mex; 
    for (int i = 0; i <= 100; ++i) {
        while (freq[i] > 0) {
            score += i;
            freq[i]--;
        }
    }
    return score;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> S(n);
        for (int i = 0; i < n; ++i) {
            cin >> S[i];
        }
        cout << get_max_score(S) << "\n";
    }
    return 0;
}
