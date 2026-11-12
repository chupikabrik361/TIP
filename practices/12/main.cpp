// Практическая работа 12. Решение задач
// Крылов Иван Андреевич

#include <iostream>
using namespace std;

int main() {
    int n, m;
    char a[100][100];
    int byl[100][100];

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            byl[i][j] = 0;
        }

    if (a[0][0] == '1') {
        cout << "Старт в стене, выбраться нельзя" << endl;
        return 0;
    }

    byl[0][0] = 1;

    bool izmenilos = true;
    while (izmenilos) {
        izmenilos = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1' || byl[i][j] == 1) continue;

                bool ryadom = false;
                if (i > 0 && byl[i - 1][j] == 1) ryadom = true;
                if (i < n - 1 && byl[i + 1][j] == 1) ryadom = true;
                if (j > 0 && byl[i][j - 1] == 1) ryadom = true;
                if (j < m - 1 && byl[i][j + 1] == 1) ryadom = true;

                if (ryadom) {
                    byl[i][j] = 1;
                    izmenilos = true;
                }
            }
        }
    }

    int pdf = 0;
    bool vyhod = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (byl[i][j] == 1 && a[i][j] == 'P') pdf++;
            if (byl[i][j] == 1 && a[i][j] == 'E') vyhod = true;
        }
    }

    if (vyhod) cout << "Максимум pdf-файлов: " << pdf << endl;
    else cout << "До выхода дойти нельзя" << endl;

    return 0;
}
