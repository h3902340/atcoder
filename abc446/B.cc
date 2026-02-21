

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> picked(m + 1, false);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        int a = 0;
        for (int j = 0; j < l; j++) {
            int x;
            cin >> x;
            if (a != 0) {
                continue;
            }
            if (!picked[x]) {
                picked[x] = true;
                a = x;
            }
        }
        cout << a << endl;
    }
    return 0;
}