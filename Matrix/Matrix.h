#ifndef INC_2_LAB_GROUP_H
#define INC_2_LAB_GROUP_H

#include <string>
#include <vector>

class Matrix {
private:
    unsigned int n = 0;
public:
    std::vector<std::vector<int>> arr;
    Matrix(unsigned int n);
    void random();
    void fromFile(std::string name);
    unsigned int getN();
    void create();
    void display();

};
#endif //INC_2_LAB_GROUP_H
