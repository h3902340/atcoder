#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    ll res = 0;
    if (A < B) {
        res = (ll)(B - A) * C;
    }
    cout << res << endl;
    return 0;
}