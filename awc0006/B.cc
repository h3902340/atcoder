#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    ll N, K, T;
    cin >> N >> K >> T;
    ll t = 0;
    for (int i = 0; i < N; i++) {
        ll D, R;
        cin >> D >> R;
        if (R >= K * D) {
            t += R;
        }
    }
    if (t >= T) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}