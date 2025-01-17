#include <iostream>
#include <ctime>
#include <thread>
#include "Matrix/Matrix.h"
#include <gtest/gtest.h>

using namespace std;

unsigned int maxThread = 4;
unsigned int N;
/**
 * function to enter N or maxThread
 * @param temp contains info about variable
 */
void enter(unsigned int &temp)
{
    while(true)
    {
        std::cin>>temp;
        if (temp>=1 && temp<=32754)
            return;
        else
            std::cout<<"Invalid, enter new: ";
    }
}
/**
 * function created standart menu in console
 */
int menu(){
    int temp;
    std::cout<<"Enter N (count of rows, colums): ";
    enter(N);
    std::cout<<"Enter count of thread: ";
    enter(maxThread);

    Matrix matrixA(N);
    Matrix matrixB(N);
    Matrix matrixC(N);

    while (true)
    {
        std::cout<<"==============================================================="<<std::endl;
        std::cout<<"1 - Random matrix A"<<std::endl;
        std::cout<<"2 - Enter matrix A"<<std::endl;
        std::cout<<"3 - matrix A from file matrixA.txt"<<std::endl;
        std::cout<<"4 - Print matrix A"<<std::endl;
        std::cout<<"5 - Random matrix B"<<std::endl;
        std::cout<<"6 - Enter matrix B"<<std::endl;
        std::cout<<"7 - matrix B from file matrixB.txt"<<std::endl;
        std::cout<<"8 - Print matrix B"<<std::endl;
        std::cout<<"9 - Calculate multiplication"<<std::endl;
        std::cout<<"10 - Print matrix C"<<std::endl;
        std::cout<<"11 - Run Google Tests"<<std::endl;
        std::cout<<"12 - Exit"<<std::endl;
        std::cout<<"==============================================================="<<std::endl;
        std::cin>>temp;

        if (temp == 1)
        {
            matrixA.random();
        }
        else if (temp == 2)
        {
            matrixA.create();
        }
        else if (temp == 3)
        {
            matrixA.fromFile("../files/matrixA.txt");
        }
        else if (temp == 4)
        {
            std::cout<<"Matrix A"<<std::endl;
            matrixA.display();
        }
        if (temp == 5)
        {
            matrixB.random();
        }
        else if (temp == 6)
        {
            matrixB.create();
        }
        else if (temp == 7)
        {
            matrixB.fromFile("../files/matrixB.txt");
        }
        else if (temp == 8)
        {
            std::cout<<"Matrix B"<<std::endl;
            matrixB.display();
        }
        else if (temp == 9)
        {
            auto time = matrixC.multiplyParallel(matrixA, matrixB);
            std::cout<<"Parallel algorithm :"<<time<<" microseconds"<<std::endl;

            time = matrixC.multiply(matrixA, matrixB);
            std::cout<<"Standart algorithm :"<<time<<" microseconds"<<std::endl;
        }
        else if (temp == 10)
        {
            std::cout<<"Matrix C"<<std::endl;
            matrixC.display();
        }
        else if (temp == 11)
        {
            ::testing::InitGoogleTest();
            return RUN_ALL_TESTS();
        }
        else if (temp == 12)
        {
            return 0;
        }
    }
}

int main() {
    srand(time(0));

    menu();
    return 0;
}