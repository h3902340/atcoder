#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N;
    cin >> N;
    int mx = 0;
    int res = 0;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (mx < h) {
            mx = h;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}