#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
    public:
    Matrix(const int& num_rows = 0, const int& num_cols = 0){
        Reset(num_rows, num_cols);
    }
    void Reset(const int& new_rows, const int& new_cols){
        if (new_rows < 0 || new_cols < 0){
            throw out_of_range("Numbers cannot be negative");
        }
        else if (new_rows == 0 || new_cols == 0){
            data = vector<vector<int>>();
            return;
        }
        data = vector<vector<int>> (new_rows, vector<int>(new_cols));
    }
    int At(const int& row, const int& col) const{
        if (row > GetNumRows() || col > GetNumColumns() || row < 0 || col < 0){
            throw out_of_range("Wrong index");
        }
        return data.at(row).at(col);
    }
    int& At(const int& row, const int& col){
        if (row > GetNumRows() || col > GetNumColumns() || row < 0 || col < 0){
            throw out_of_range("Wrong index");
        }
        return data.at(row).at(col);
    }
    int GetNumRows() const{
        return data.size();
    }
    int GetNumColumns() const{
        return data.size() ? data[0].size() : 0;
    }
    private:
    vector<vector<int>> data;
};


istream& operator >>(istream& stream, Matrix& matrix){
    int n, m;
    stream >> n >> m;
    matrix.Reset(n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int temp;
            stream >> temp;
            matrix.At(i, j) = temp;
        }
    }
    return stream;
}

ostream& operator <<(ostream& stream, const Matrix& matrix){
    stream << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
    for (int i = 0; i < matrix.GetNumRows(); i++){
        for (int j = 0; j < matrix.GetNumColumns(); j++){
            int temp;
            stream << matrix.At(i, j) << ' ';
        }
        stream << endl;
    }
    return stream;
}

bool operator ==(const Matrix& lhs, const Matrix& rhs){
    if (lhs.GetNumColumns() == rhs.GetNumColumns() && lhs.GetNumRows() == rhs.GetNumRows()){
        for (int i = 0; i < lhs.GetNumRows(); i++){
            for (int j = 0; j < lhs.GetNumColumns(); j++){
                if (lhs.At(i, j) != rhs.At(i, j)){
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

Matrix operator +(const Matrix& lhs, const Matrix& rhs){
    if (lhs.GetNumRows() != rhs.GetNumRows()){
        throw invalid_argument("Missmatched number of rows");
    }

    if (lhs.GetNumColumns() != rhs.GetNumColumns()){
        throw invalid_argument("Missmatched number of columns");
    }

    Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

    for (int i = 0; i < result.GetNumRows(); i++){
        for (int j = 0; j < result.GetNumColumns(); j++){
            result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return result;
}

int main() {
    Matrix one(5, 0);
    Matrix two(0, 7);
    cout << one + two;
    return 0;
}
