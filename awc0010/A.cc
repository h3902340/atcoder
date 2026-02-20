#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, M;
    cin >> N >> M;
    ll s = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s += a;
    }
    if (s >= M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}