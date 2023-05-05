#include <iostream>
#include <map>

constexpr unsigned long long LIMIT = 4294967161;

void
multiplication(std::map<unsigned, std::map<unsigned, unsigned>> &matrix1, 
        std::map<unsigned, std::map<unsigned, unsigned>> &matrix2)
{
    std::map<unsigned, std::map<unsigned, unsigned>> matrix_rez;
    for (auto &y : matrix1) {
        for (auto &x : y.second) {   //all elems in matrix1
            if (matrix2.contains(x.first)) {
                for (auto &v : matrix2[x.first]) {
                    matrix_rez[y.first][v.first] = ((unsigned long long)matrix_rez[y.first][v.first] + 
                                                    ((unsigned long long)x.second * (unsigned long long)v.second) % LIMIT) % LIMIT;
                }
            }
        }
    }
    for (auto &y : matrix_rez) {
        for (auto &x : y.second) {
            if (x.second != 0) {
                std::cout << y.first << ' ' << x.first << ' ' << x.second << std::endl;
            }
        }
    }
}

int 
main(void)
{
    unsigned r = 0;
    unsigned c = 0;
    unsigned v = 0;
    std::map<unsigned, std::map<unsigned, unsigned>> matrix1;
    while (std::cin >> r) {
        std::cin >> c;
        std::cin >> v;
        if (r == 0 && c == 0 && v == LIMIT) {
            break;
        }
        matrix1[r][c] = v;
    }
    std::map<unsigned, std::map<unsigned, unsigned>> matrix2;
    while (std::cin >> r) {
        std::cin >> c;
        std::cin >> v;
        matrix2[r][c] = v;
    }
    multiplication(matrix1, matrix2);
    return 0;
}
