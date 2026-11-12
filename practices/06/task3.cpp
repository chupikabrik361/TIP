// задание 3
#include <iostream>
using namespace std;

int a[10000], b[10000];

int main() {
    int x, n, len;
    cin >> x >> n;

    if (x == 100) { a[0] = 1; a[1] = 0; a[2] = 0; len = 3; }
    else if (x >= 10) { a[0] = x / 10; a[1] = x % 10; len = 2; }
    else { a[0] = x; len = 1; }

    for (int s = 1; s < n; s++) {
        int k = 0, i = 0;
        while (i < len) {
            int j = i;
            while (j < len && a[j] == a[i]) j++;
            b[k++] = j - i;
            b[k++] = a[i];
            i = j;
        }
        for (i = 0; i < k; i++) a[i] = b[i];
        len = k;
    }

    for (int i = 0; i < len; i++) cout << a[i];
}
