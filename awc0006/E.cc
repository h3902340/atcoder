#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int N = 2e5;
class FenwickTree {
    ll tree[N];
    int sz;

   public:
    FenwickTree(int n) {
        sz = n + 1;
        for (int i = 1; i < sz; i++) {
            tree[i] = 0;
        }
    }
    void add(int i, ll delta) {
        i++;
        while (i < sz) {
            tree[i] += delta;
            i += i & -i;
        }
    }
    ll query(int i) {
        i++;
        ll s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }
};

int main() {
    ll N, Q;
    cin >> N >> Q;
    FenwickTree t(N);
    vector<ll> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        t.add(i, S[i]);
    }
    vector<ll> res;
    for (int i = 0; i < Q; i++) {
        int type, arg1, arg2;
        cin >> type >> arg1 >> arg2;
        if (type == 1) {
            ll a = t.query(arg2 - 1);
            if (arg1 > 1) {
                a -= t.query(arg1 - 2);
            }
            res.push_back(a);
        } else {
            t.add(arg1 - 1, arg2 - S[arg1 - 1]);
            S[arg1 - 1] = arg2;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}