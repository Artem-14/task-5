#include <iostream>
#include <vector>
#include <locale>

int josephus(int n, int k) {
    if (n == 1) {
        return 0;
    }
    return (josephus(n - 1, k) + k) % n;
}

int findK(int n) {
    for (int k = 2; k < n; ++k) {
        if (josephus(n, k) == 0) {
            return k;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "rus");

    int n, k;
    std::cout << "Введите количество человек (n): ";
    std::cin >> n;

    std::cout << "Введите шаг (k): ";
    std::cin >> k;

    int last_person = josephus(n, k) + 1;
    std::cout << "Последний оставшийся в живых человек: " << last_person << std::endl;

    int optimal_k = findK(n);
    if (optimal_k != -1) {
        std::cout << "Такое значение k > 1, чтобы остался первый человек: " << optimal_k << std::endl;
    }
    else {
        std::cout << "Не удалось найти подходящее значение k." << std::endl;
    }

    return 0;
}
