#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll s = 0;
    for (int i = 0; i < K; i++) {
        s += a[i];
    }
    int res = 0;
    if (s <= 0) {
        res++;
    }
    int j = 0;
    for (int i = K; i < N; i++) {
        s += a[i] - a[j];
        j++;
        if (s <= 0) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}