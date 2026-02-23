#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
    vector<vector<ll>> dp2(N + 1, vector<ll>(M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j - A[i] < 0) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - A[i]] + B[i]);
            }
            int r = N - 1 - i;
            if (j - A[r] < 0) {
                dp2[r][j] = dp2[r + 1][j];
            } else {
                dp2[r][j] = max(dp2[r + 1][j], dp2[r + 1][j - A[r]] + B[r]);
            }
        }
    }
    ll mx = dp[N][M];
    for (int k = 0; k < N; k++) {
        ll v = mx - B[k];
        int b = M - A[k];
        bool ok = false;
        for (int j = 0; j <= b; j++) {
            if (dp[k][j] + dp2[k + 1][b - j] == v) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}