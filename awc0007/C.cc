#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, K;
    cin >> N >> K;
    int mx = 0;
    int mxi = -1;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (mx < a) {
            mx = a;
            mxi = i;
        }
    }
    cout << mxi + 1 << endl;
    return 0;
}