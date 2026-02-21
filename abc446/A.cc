
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    s[0] -= 'A';
    s[0] += 'a';
    cout << "Of" + s << endl;
    return 0;
}