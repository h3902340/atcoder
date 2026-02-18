#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, W, K;
    cin >> N >> W >> K;
    if ((N - 1) * K <= W) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}