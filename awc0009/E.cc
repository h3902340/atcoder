#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define lg2(n) (31 - __builtin_clz(n))
const int N = 1e5;
const int LGN = lg2(N) + 1;
class RMQ {
    int rmq[N][LGN];
    int rmq2[N][LGN];

   public:
    void init(vector<int>& arr, int n) {
        int lgn = lg2(n);
        for (int i = 0; i < n; i++) {
            rmq[i][0] = arr[i];
            rmq2[i][0] = arr[i];
        }
        int k = 1;
        for (int l = 1; l <= lgn; l++) {
            int cap = n - (k << 1) + 1;
            for (int i = 0; i < cap; i++) {
                rmq[i][l] = max(rmq[i][l - 1], rmq[i + k][l - 1]);
                rmq2[i][l] = min(rmq2[i][l - 1], rmq2[i + k][l - 1]);
            }
            k <<= 1;
        }
    }
    int findMax(int i, int j) {
        int k = lg2(j - i + 1);
        return max(rmq[i][k], rmq[j - (1 << k) + 1][k]);
    }
    int findMin(int i, int j) {
        int k = lg2(j - i + 1);
        return min(rmq2[i][k], rmq2[j - (1 << k) + 1][k]);
    }
};
RMQ rmq;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    rmq.init(A, N);
    vector<int> res(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        res[i] = rmq.findMax(l - 1, r - 1) - rmq.findMin(l - 1, r - 1);
    }
    for (int i = 0; i < Q; i++) {
        cout << res[i] << endl;
    }
    return 0;
}