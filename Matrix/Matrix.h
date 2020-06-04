#ifndef INC_2_LAB_GROUP_H
#define INC_2_LAB_GROUP_H

#include <string>
#include <vector>

class Matrix {
private:
    unsigned int n = 0;
public:
    std::vector<std::vector<long long int>> arr;

    Matrix(unsigned int n);
    void random();
    void fromFile(std::string name);
    unsigned int getN();
    void create();
    void display();
    long long int multiply(Matrix A, Matrix B, int temp = -1);
    long long int multiplyParallel(Matrix A, Matrix B);

};
extern unsigned int maxThread;
#endif //INC_2_LAB_GROUP_H
