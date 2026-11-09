// Практическая работа 11. Решение задач
// Крылов Иван Андреевич

#include <iostream>
using namespace std;

int main() {
    int zadacha;
    cout << "Введите номер задачи (1, 2 или 3): ";
    cin >> zadacha;

    // Задача 1
    if (zadacha == 1) {
        int n, m;
        int a[100][100];
        int s[100][100];
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) s[i][j] = a[i][j];
                else if (i == 0) s[i][j] = s[i][j - 1] + a[i][j];
                else if (j == 0) s[i][j] = s[i - 1][j] + a[i][j];
                else if (s[i - 1][j] > s[i][j - 1]) s[i][j] = s[i - 1][j] + a[i][j];
                else s[i][j] = s[i][j - 1] + a[i][j];
            }
        }

        int x[200], y[200];
        int k = 0;
        int i = n - 1, j = m - 1;
        while (i > 0 || j > 0) {
            x[k] = i;
            y[k] = j;
            k++;
            if (i == 0) j--;
            else if (j == 0) i--;
            else if (s[i - 1][j] > s[i][j - 1]) i--;
            else j--;
        }
        x[k] = 0;
        y[k] = 0;

        cout << "Сумма баллов: " << s[n - 1][m - 1] << endl;
        for (int t = k; t >= 0; t--) {
            cout << x[t] << " " << y[t] << endl;
        }
    }

    // Задача 2
    if (zadacha == 2) {
        int n, d;
        int c[1000];
        cin >> n >> d;
        for (int i = 0; i < n; i++) cin >> c[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (c[j] > c[j + 1]) {
                    int tmp = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = tmp;
                }
            }
        }

        int raznica = 0;
        int dney = 1;
        int pervyi = c[0];
        for (int i = 1; i < n; i++) {
            if (c[i] - pervyi > raznica) {
                dney++;
                pervyi = c[i];
            }
        }
        if (dney <= d) break;
        raznica++;
        cout << "Минимальная разница: " << raznica << endl;
    }

    // Задача 3
    if (zadacha == 3) {
        int n, k, l;
        cin >> n >> k >> l;
        int c[n+1];
        for (int i = 0; i < n; i++) cin >> c[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (c[j] < c[j + 1]) {
                    int tmp = c[j];
                    c[j] = c[j + 1];
                    c[j + 1] = tmp;
                }
            }
        }

        int summa = 0;
        int vzyali = 0;
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < l; t++) {
                if (vzyali < k) {
                    summa = summa + c[i];
                    vzyali++;
                }
            }
        }
        cout << "Максимальная стоимость букета: " << summa << endl;
    }

    return 0;
}
