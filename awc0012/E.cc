#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
struct Data {
    ll v;
    int i;
};
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll res = 0;
    vector<ll> dp(N);
    vector<Data> deque(N);
    int l = 0;
    int r = -1;
    for (int i = 0; i < N; i++) {
        while (l <= r && i - deque[l].i > K) {
            l++;
        }
        dp[i] = A[i];
        if (l <= r) {
            dp[i] += deque[l].v;
        }
        while (l <= r && deque[r].v <= dp[i]) {
            r--;
        }
        deque[++r] = {dp[i], i};
    }
    cout << dp[N - 1] << endl;
    return 0;
}