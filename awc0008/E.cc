#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int N = 2e5;
class FenwickTree {
    int tree[N + 1];
    int sz;

   public:
    FenwickTree(int n) {
        sz = n + 1;
        for (int i = 1; i < sz; i++) {
            tree[i] = 0;
        }
    }
    void add(int i, int delta) {
        i++;
        while (i < sz) {
            tree[i] += delta;
            i += i & -i;
        }
    }
    int query(int i) {
        i++;
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> inv(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        inv[A[i] - 1] = i;
    }
    FenwickTree t(N);
    ll res = 0;
    for (int i = 0; i < N; i++) {
        int j = inv[i];
        int k = t.query(j);
        res += j - i + k;
        t.add(0, 1);
        t.add(j, -1);
    }
    cout << res << endl;
    return 0;
}