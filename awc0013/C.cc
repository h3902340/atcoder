#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

#define ll long long
int main() {
    int N, K;
    cin >> N >> K;
    K--;
    int res = 0;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < N; i++) {
        if (S[i] < S[K]) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}