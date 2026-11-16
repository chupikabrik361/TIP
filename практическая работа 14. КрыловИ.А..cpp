// Практическая работа 14. Решение задач
// Крылов Иван Андреевич

#include <iostream>
using namespace std;

int main() {
    int zadacha = 0;
    cout << "Введите номер задачи (1, 2 или 3): ";
    cin >> zadacha;
    char stroka[4002];
    cin.getline(stroka, 4002);

    // Задача 1
    if (zadacha == 1) {
        int skobki[1000];
        int n = 0;
        bool pravilno = true;
        cin.getline(stroka, 4002);

        for (int i = 0; stroka[i] != 0; i++) {
            int c = stroka[i];
            if (c == '(' || c == '[' || c == '{') {
                if (n == 1000) {
                    pravilno = false;
                    break;
                }
                skobki[n] = c;
                n++;
            }

            if (c == ')' || c == ']' || c == '}') {
                int para = '(';
                if (c == ']') para = '[';
                if (c == '}') para = '{';

                if (n == 0 || skobki[n - 1] != para) {
                    pravilno = false;
                    break;
                }
                n--;
            }
        }

        if (pravilno && n == 0) cout << "yes\n";
        else cout << "no\n";
    }

    // Задача 2
    if (zadacha == 2) {
        cout << "Введите текст одной строкой и нажмите Enter.\n";
        cin.getline(stroka, 1002);
        if (!cin && !cin.eof()) {
            cout << "Слишком длинная строка\n";
            return 0;
        }

        char slova[501][1002];
        int vsego = 0;
        char slovo[1002];
        int n = 0;
        bool defis = false;
        char alfavit[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";

        for (int i = 0; ; i++) {
            char c = stroka[i];
            char vtoroi = 0;
            bool bukva = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');

            
            if (c != 0 && !bukva) {
                for (int j = 0; alfavit[j] != 0; j += 2) {
                    if (c == alfavit[j] && stroka[i + 1] == alfavit[j + 1]) {
                        vtoroi = stroka[i + 1];
                        bukva = true;
                        i++;
                        break;
                    }
                }
            }

            if (bukva) {
                if (defis) slovo[n++] = '-';
                slovo[n++] = c;
                if (vtoroi != 0) slovo[n++] = vtoroi;
                defis = false;
            } else if (c == '-' && n > 0 && !defis) {
                defis = true;
            } else if (n > 0) {
                slovo[n] = 0;
                bool povtor = false;
                for (int j = 0; j < vsego; j++) {
                    int k = 0;
                    while (k < n && slova[j][k] == slovo[k]) k++;
                    if (k == n && slova[j][k] == 0) {
                        povtor = true;
                        break;
                    }
                }

                if (!povtor) {
                    cout << slovo << endl;
                    for (int j = 0; j <= n; j++) slova[vsego][j] = slovo[j];
                    vsego++;
                }

                n = 0;
                defis = false;
            }

            if (c == 0) break;
        }
    }

    // Задача 3
    if (zadacha == 3) {
        int stek[1000];
        int minimum[1000];
        int n = 0;
        int komanda;

        cout << "1 - добавить, 2 - снять, 3 - минимум, 4 - пуст ли стек, 0 - выход\n";

        while (cin >> komanda && komanda != 0) {
            if (komanda == 1) {
                int chislo;
                if (!(cin >> chislo)) break;

                if (n == 1000) {
                    cout << "Стек полон\n";
                } else {
                    stek[n] = chislo;
                    minimum[n] = chislo;
                    if (n > 0 && minimum[n - 1] < chislo) {
                        minimum[n] = minimum[n - 1];
                    }
                    n++;
                }
            }

            if (komanda == 2) {
                if (n == 0) cout << "Стек пуст\n";
                else {
                    n--;
                    cout << stek[n] << endl;
                }
            }

            if (komanda == 3) {
                if (n == 0) cout << "Стек пуст\n";
                else cout << minimum[n - 1] << endl;
            }

            if (komanda == 4) cout << boolalpha << (n == 0) << endl;
        }
    }

    return 0;
}





