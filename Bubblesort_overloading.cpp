
#include <iostream>
using namespace std;

class matrixType {
private:
    int rows, cols;
    double** matrix;

public:
    // Constructor to initialize a matrix with given rows and columns
    matrixType(int r, int c) {
        rows = r;
        cols = c;
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    // Destructor to deallocate memory
    ~matrixType() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Method to set values of the matrix
    void setMatrix() {
        cout << "Enter values for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    // Overload the << operator to print the matrix
    friend ostream& operator<<(ostream& out, const matrixType& mat) {
        for (int i = 0; i < mat.rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                out << mat.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Overload the + operator for matrix addition
    matrixType operator+(const matrixType& mat) {
        if (rows != mat.rows || cols != mat.cols) {
            throw invalid_argument("Matrices must have the same dimensions for addition.");
        }

        matrixType result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
            }
        }
        return result;
    }

    // Overload the * operator for matrix multiplication
    matrixType operator*(const matrixType& mat) {
        if (cols != mat.rows) {
            throw invalid_argument("Number of columns of the first matrix must match the number of rows of the second matrix.");
        }

        matrixType result(rows, mat.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < mat.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * mat.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    try {
        // Define two matrices
        int rows1, cols1, rows2, cols2;
        cout << "Enter rows and columns for Matrix A: ";
        cin >> rows1 >> cols1;
        matrixType A(rows1, cols1);
        A.setMatrix();

        cout << "Enter rows and columns for Matrix B: ";
        cin >> rows2 >> cols2;
        matrixType B(rows2, cols2);
        B.setMatrix();

        // Display matrices
        cout << "\nMatrix A:\n" << A;
        cout << "Matrix B:\n" << B;

        // Perform addition if possible
        if (rows1 == rows2 && cols1 == cols2) {
            matrixType C = A + B;
            cout << "\nMatrix A + Matrix B:\n" << C;
        } else {
            cout << "\nMatrix addition not possible due to incompatible dimensions.\n";
        }

        // Perform multiplication if possible
        if (cols1 == rows2) {
            matrixType D = A * B;
            cout << "\nMatrix A * Matrix B:\n" << D;
        } else {
            cout << "\nMatrix multiplication not possible due to incompatible dimensions.\n";
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
