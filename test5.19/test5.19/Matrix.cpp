#include"head.h"
template<typename t>
class matrix {
private:
    int rows, cols;
    std::vector<std::vector<t>> data;

public:
    matrix(int r, int c, const t& val = t()) : rows(r), cols(c), data(r, std::vector<t>(c, val)) {}

    t& operator()(int i, int j) { return data[i][j]; }
    const t& operator()(int i, int j) const { return data[i][j]; }

    int numrows() const { return rows; }
    int numcols() const { return cols; }

    matrix<t> operator+(const matrix<t>& other) const {
        matrix<t> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other(i, j);
        return result;
    }

    // 可继续添加 operator-, operator*, 转置、行列式、逆矩阵等功能
};
