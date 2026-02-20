#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> area(N);
    int idx = -1;
    int pre = INT32_MAX;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (abs(pre - a) > K) {
            idx++;
        }
        area[i] = idx;
        pre = a;
    }
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        if (area[l - 1] == area[r - 1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}