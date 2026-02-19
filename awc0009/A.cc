#include <iostream>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int K, M;
    cin >> K >> M;
    int res = 0;
    for (int i = 0; i < K; i++) {
        int l;
        cin >> l;
        res += l;
    }
    cout << res % M << endl;
    return 0;
}