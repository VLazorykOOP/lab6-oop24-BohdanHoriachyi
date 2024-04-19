#include <iostream>

#include <cmath>

class abstrakt {
public:
    virtual double norm() const = 0;
    virtual ~abstrakt() {}
    virtual void printNorm() const = 0;
};

class complexnumber : public abstrakt {
private:
    double real;
    double img;
public:
    complexnumber(double r, double i) : real(r), img(i) {}
    double norm() const override {
        return real * real + img * img;
    }
    virtual void printNorm() const override {
        std::cout << "Norm of complexnumber" << norm() << std::endl;
    }
};

class vector : public abstrakt {
private:
    double el[10];
public:
    vector(double arr[10]) {
        for (int i = 0; i < 10; ++i) {
            el[i] = arr[i];
        }
    }
    double norm() const override {
        double sumOfSquares = 0.0;
        for (int i = 0; i < 10; ++i) {
            sumOfSquares += el[i] * el[i];
        }
        return std::sqrt(sumOfSquares);
    }
    virtual void printNorm() const override {
        std::cout << "Norm of vector" << norm() << std::endl;
    }
};

class matrix : public abstrakt {
private:
    double el[2][2];
public:
    matrix(double arr[2][2]) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                el[i][j] = arr[i][j];
            }
        }
    }
    double norm() const override {
        double sumOfSquares = 0.0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                sumOfSquares += el[i][j] * el[i][j];
            }
        }
        return std::sqrt(sumOfSquares);
    }
    virtual void printNorm() const override {
        std::cout << "Norm of matrix" << norm() << std::endl;
    }
};

int main() {
    double vectorElements[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double matrixElements[2][2] = { {1, 2}, {3, 4} };

    complexnumber cn(3, 4);
    vector vec(vectorElements);
    matrix mat(matrixElements);

    cn.printNorm();
    vec.printNorm();
    mat.printNorm();

    return 0;
}