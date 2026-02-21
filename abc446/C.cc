

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (a[j] < b[i]) {
                b[i] -= a[j];
                a[j] = 0;
                j++;
            }
            a[j] -= b[i];
            while (i - j >= d) {
                a[j++] = 0;
            }
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
        }
        cout << s << endl;
    }
    return 0;
}