#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, L, W;
    cin >> N >> L >> W;
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (D[i] >= L - W && D[i] <= L + W) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}