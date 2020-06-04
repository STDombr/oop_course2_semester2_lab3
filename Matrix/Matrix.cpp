#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

Matrix::Matrix(unsigned int n)
{
    this->n = n;

    std::vector<long long int> temp;
    for(int j = 0; j<n; j++)
        temp.push_back(0);
    for(int i = 0; i<n; i++)
        arr.push_back(temp);
}

void Matrix::random()
{
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            arr[i][j] = rand()%1000 - 500;
}

unsigned int Matrix::getN()
{
    return n;
}

void Matrix::create()
{
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


long long int Matrix::multiply(Matrix A, Matrix B, int temp)
{
    auto b2 = std::chrono::steady_clock::now();

    if (temp == -1)
    {
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
            {
                this->arr[i][j] = 0;
                for (int k=0; k<n; k++)
                    this->arr[i][j] += A.arr[i][k] * B.arr[k][j];
            }
    }
    else
    {
        int i = temp;
        while (i<n)
        {
            for (int j=0; j<n; j++)
            {
                this->arr[i][j] = 0;
                for (int k=0; k<n; k++)
                    this->arr[i][j] += A.arr[i][k] * B.arr[k][j];
            }
            i += maxThread;
        }
    }

    auto e2 = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(e2 - b2).count();
}


long long int Matrix::multiplyParallel(Matrix A, Matrix B)
{
    auto b1 = std::chrono::steady_clock::now();

    std::thread threads[maxThread];
    for (int i=0; i<maxThread; i++)
        threads[i] = std::thread(&Matrix::multiply, this, A, B, i);
    for (int i=0; i<maxThread; i++)
        threads[i].join();

    auto e1 = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(e1 - b1).count();
}