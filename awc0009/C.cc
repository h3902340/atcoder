#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, T, K;
    cin >> N >> T >> K;
    vector<int> h(N);
    int mn = INT32_MAX;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        mn = min(mn, h[i]);
    }
    mn--;
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (h[i] - mn <= T + K) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}