// Brute-force minimax solver for the Poby vs Rekkles game (for small subarrays).
// Usage: compile and run. It reads the same input format as the problem.
// For queries with length <= MAX_BRUTE it computes exact value by minimax+memo.
// For longer queries it prints a heuristic (sum of ceil(log2)), which you can ignore
// while using this program to explore small cases and infer patterns.

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
struct Key {
    vi v;
    int turn; // 0 = Poby, 1 = Rekkles
    bool operator<(Key const& o) const {
        if (turn != o.turn) return turn < o.turn;
        return v < o.v;
    }
};

int MAX_BRUTE = 16;
map<Key,int> memo;

bool terminal_state(const vi &v){
    for(int x: v) if (x != 1) return false;
    return true;
}

int ceil_log2_longlong(long long x){
    // returns ceil(log2(x)) for x >= 1
    if (x <= 1) return 0;
    int l = 0;
    long long p = 1;
    while(p < x){ p <<= 1; l++; }
    return l;
}

// exact minimax: returns minimal number of Poby moves remaining from state v (turn indicates whose move it is)
// Poby wants to minimize the count of his own moves; Rekkles wants to maximize that count.
// We count only Poby's moves. When Poby makes a move, the returned value includes that +1.
int solve_minimax(vi v, int turn){
    // sort state to canonical form (symmetry)
    sort(v.begin(), v.end(), greater<int>());

    Key k{v, turn};
    auto it = memo.find(k);
    if (it != memo.end()) return it->second;

    if (terminal_state(v)) {
        memo[k] = 0;
        return 0;
    }

    if (turn == 0) {
        // Poby's turn: he must pick an index with >=2 and replace with floor(x/2).
        int best = INT_MAX;
        for(size_t i=0;i<v.size();++i){
            if (v[i] >= 2){
                vi nv = v;
                nv[i] = nv[i] / 2; // floor
                int res = solve_minimax(nv, 1);
                if (res != INT_MAX) best = min(best, 1 + res); // Poby used one move
            }
        }
        if (best == INT_MAX) best = INT_MAX; // no legal move (shouldn't happen unless all ones)
        memo[k] = best;
        return best;
    } else {
        // Rekkles' turn: picks an index with >=2 and replace with x+1, trying to maximize Poby's moves.
        int best = INT_MIN;
        for(size_t i=0;i<v.size();++i){
            if (v[i] >= 2){
                vi nv = v;
                nv[i] = nv[i] + 1;
                int res = solve_minimax(nv, 0);
                best = max(best, res);
            }
        }
        // if Rekkles has no legal move, then it's terminal (shouldn't happen)
        if (best == INT_MIN) best = 0;
        memo[k] = best;
        return best;
    }
}

int heuristic_answer(const vi &v) {
    // simple heuristic: sum of ceil(log2(x))
    int s = 0;
    for(int x : v) s += ceil_log2_longlong(x);
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        while(q--){
            int l,r; cin >> l >> r;
            int len = r - l + 1;
            vi sub;
            sub.reserve(len);
            for(int i=l;i<=r;i++) sub.push_back(a[i]);

            if (len <= MAX_BRUTE) {
                memo.clear();
                int ans = solve_minimax(sub, 0); // Poby moves first
                cout << ans << "\n";
            } else {
                // Fallback heuristic for large queries — useful only as placeholder.
                cout << heuristic_answer(sub) << "\n";
            }
        }
    }
    return 0;
}
