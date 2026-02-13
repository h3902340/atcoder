#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        int p, v;
        cin >> p >> v;
        s[p - 1] = v;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < k) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}