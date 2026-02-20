#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N;
    cin >> N;
    ll res = 0;
    int pre = INT32_MAX;
    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        if (pre < cur) {
            res += (cur >> 1);
        } else {
            res += cur;
        }
        pre = cur;
    }
    cout << res << endl;
    return 0;
}