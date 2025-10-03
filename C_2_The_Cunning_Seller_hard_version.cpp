// Utkarsh Sahay - solution
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using u64 = unsigned long long;

unsigned long long sumDigitsUpto(long long N) {
    if (N < 0) return 0ULL;
    unsigned long long res = 0;
    unsigned long long pow10 = 1;
    while (pow10 <= (unsigned long long)N) {
        unsigned long long higher = (unsigned long long)N / (pow10 * 10ULL);
        unsigned long long current = ((unsigned long long)N / pow10) % 10ULL;
        unsigned long long lower = (unsigned long long)N % pow10;
        unsigned long long contrib = higher * 45ULL * pow10
                                     + current * (lower + 1ULL)
                                     + (current * (current - 1ULL) / 2ULL) * pow10;
        res += contrib;
        if (pow10 > (unsigned long long)LLONG_MAX / 10ULL) break; 
        pow10 *= 10ULL;
    }
    return res;
}

unsigned long long sumDigitsRange(long long L, long long R) {
    if (L > R) return 0ULL;
    return sumDigitsUpto(R) - sumDigitsUpto(L - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k;
        cin >> k;

        unsigned long long remaining = k;
        unsigned long long totalSum = 0ULL;

        long long d = 1;
        long long start = 1;

        while (remaining > 0) {
            unsigned long long cnt;
            if (d == 1) cnt = 9ULL;
            else {
                unsigned long long p = 1;
                for (int i = 1; i < d; ++i) p *= 10ULL;
                cnt = 9ULL * p;
            }
            unsigned long long groupDigits = cnt * (unsigned long long)d;

            if (remaining >= groupDigits) {
                long long L = start;
                long long R = start + (long long)cnt - 1;
                totalSum += sumDigitsRange(L, R);
                remaining -= groupDigits;
                ++d;
                start *= 10;
            } else {
                unsigned long long fullNums = remaining / d;
                unsigned long long remDigits = remaining % d; 

                if (fullNums > 0) {
                    long long L = start;
                    long long R = start + (long long)fullNums - 1;
                    totalSum += sumDigitsRange(L, R);
                }

                if (remDigits > 0) {
                    long long nextNum = start + (long long)fullNums;
                    string s = to_string(nextNum);
                    for (unsigned long long i = 0; i < remDigits; ++i) {
                        totalSum += (unsigned long long)(s[i] - '0');
                    }
                }

                remaining = 0;
                break;
            }
        }

        cout << totalSum << '\n';
    }
    return 0;
}
