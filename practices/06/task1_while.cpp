#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 0;
    while (i<n) {
        int j = 0;
        while (j<n) {
            if (i + j < n - 1) cout << 0;
            else if (i + j == n - 1) cout << 1;
            else cout << 2;
            if (j < n - 1) cout << ' ';
            ++j;
        }
        cout << '\n';
        ++i;
    }
    return 0;
}
