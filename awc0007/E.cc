#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int dis(ll a, ll b, int n) {
    int ax = 1 + (a - 1) % n;
    int ay = (a + n - 1) / n;
    int bx = 1 + (b - 1) % n;
    int by = (b + n - 1) / n;
    return abs(ax - bx) + abs(ay - by);
}

int main() {
    int N, M;
    cin >> N >> M;
    ll S, T;
    cin >> S >> T;
    if (M == 0) {
        ll res = dis(S, T, N);
        cout << res << endl;
        return 0;
    }
    vector<ll> P(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i];
    }
    int cap = 1 << M;
    vector<vector<ll>> dp(cap, vector<ll>(M, -1));
    for (int i = 1; i < cap; i++) {
        for (int j = 0; j < M; j++) {
            int b = 1 << j;
            if (i & b) {
                int ii = i ^ b;
                if (ii == 0) {
                    dp[i][j] = dis(S, P[j], N);
                    break;
                }
                for (int k = 0; k < M; k++) {
                    if (dp[ii][k] == -1) {
                        continue;
                    }
                    ll d = dp[ii][k] + dis(P[k], P[j], N);
                    if (dp[i][j] == -1) {
                        dp[i][j] = d;
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], d);
                }
            }
        }
    }
    ll res = INT64_MAX;
    for (int i = 0; i < M; i++) {
        res = min(res, dp[cap - 1][i] + dis(P[i], T, N));
    }
    cout << res << endl;
    return 0;
}