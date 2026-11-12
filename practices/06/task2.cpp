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
