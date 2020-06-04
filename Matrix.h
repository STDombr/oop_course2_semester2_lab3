#ifndef INC_2_LAB_GROUP_H
#define INC_2_LAB_GROUP_H

#include <string>
#include <vector>

class Matrix {
private:
    int n;
public:
    std::vector<std::vector<int>> arr;
    Matrix(int n);
    void random();
    void fromFile(std::string name);
    int getN();
    void create();
    void display();

};
#endif //INC_2_LAB_GROUP_H