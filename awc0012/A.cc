#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, T;
    cin >> N >> T;
    ll res = 0;
    vector<int> H(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < N; i++) {
        if (H[i] <= T) {
            res += C[i];
        }
    }
    cout << res << endl;
    return 0;
}