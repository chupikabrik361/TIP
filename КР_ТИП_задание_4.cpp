#include <iostream>
#include <cmath>
int main() {
    int a;
    int b;
    int c;
    int d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    if (d == 'J') {
        std::cout << "Krylov Ivan";
    }
    if (d == 'k') {
        if (a == 0) {
            if (b == 0) {
                if (c == 0) std::cout << "Бесконечно много корней" << std::endl;
                else std::cout << "Корней нет" << std::endl;
            } else {
                std::cout << "Линейное уравнение, x = " << -c / b << std::endl;
            }
        } else {
            double D = b * b - 4 * a * c;

            if (D > 0) {
                double x1 = (-b + sqrt(D)) / (2 * a);
                double x2 = (-b - sqrt(D)) / (2 * a);
                std::cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << std::endl;
            } else if (D == 0) {
                double x = -b / (2 * a);
                std::cout << "Один корень: x = " << x << std::endl;
            } else {
                std::cout << "Действительных корней нет" << std::endl;
            }
        }
    }
    if (d == 'n') {
        int i;
        std::cin >> i;
        if (i%7 == 0) {
            std::cout << 'True' << std::endl;
        }
        else {
            std::cout << 'False' << std::endl;
        }
    }
    return 0;
}