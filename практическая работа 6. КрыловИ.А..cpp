// задание 1
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n - 1) cout << 0;
            else if (i + j == n - 1) cout << 1;
            else cout << 2;
            if (j < n - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}

// второй вариант решения задания

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
            j=j++;
        }
        cout << '\n';
        i=i++;
    }
    return 0;
}

// задание 2
#include <iostream>
using namespace std;

int main() {
    int n, m, w, x, y;
    int a[34][34] = {};
    cin >> n >> m >> w;
    for (int k = 0; k < w; k++) {
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                cout << '*';
            } else {
                cout << a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + a[i][j-1] + a[i][j+1] + a[i+1][j-1] + a[i+1][j] + a[i+1][j+1];
            }
        }
        cout << '\n';
    }
}

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