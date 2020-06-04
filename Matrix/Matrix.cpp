#include "Matrix.h"
#include <iostream>
#include <fstream>

Matrix::Matrix(unsigned int n)
{
    this->n = n;

    std::vector<int> temp;
    for(int j = 0; j<n; j++)
        temp.push_back(0);
    for(int i = 0; i<n; i++)
        arr.push_back(temp);
}

void Matrix::random()
{
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            arr[i][j] = rand()%10000;
}

unsigned int Matrix::getN()
{
    return n;
}

void Matrix::create()
{
    int elem;
    std::cout<<"Enter "<<n*n<<" elements:"<<std::endl;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            std::cin>>arr[i][j];
}

void Matrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout<<arr[i][j]<<" ";
        std::cout<<std::endl;
    }
}

void Matrix::fromFile(std::string name)
{
    std::ifstream fileA;
    fileA.open(name);
    int temp, count = 0;
    while (fileA >> temp && count < n*n)
    {
        this->arr[count / n][count % n] = temp;
        count++;
    }
}
