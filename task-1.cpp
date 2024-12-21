#include <iostream>
#include <vector>
#include <locale>

void fillSpiralMatrix(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));

    int value = 1;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (value <= m * n) {
        for (int i = left; i <= right && value <= m * n; ++i) {
            matrix[top][i] = value++;
        }
        ++top;

        for (int i = top; i <= bottom && value <= m * n; ++i) {
            matrix[i][right] = value++;
        }
        --right;

        for (int i = right; i >= left && value <= m * n; --i) {
            matrix[bottom][i] = value++;
        }
        --bottom;

        for (int i = bottom; i >= top && value <= m * n; --i) {
            matrix[i][left] = value++;
        }
        ++left;
    }

    std::cout << "Спиральная матрица:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int m, n;
    std::cout << "Введите размеры матрицы (m x n): ";
    std::cin >> m >> n;

    fillSpiralMatrix(m, n);

    return 0;
}
