#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    if (S > T) {
        swap(S, T);
    }
    ll s = 0;
    for (int i = 0; i < M; i++) {
        int p, v;
        cin >> p >> v;
        if (p >= S && p <= T) {
            s += v;
        }
    }
    cout << s << endl;
    return 0;
}