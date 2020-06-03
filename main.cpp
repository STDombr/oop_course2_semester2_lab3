#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include "Matrix.h"

using namespace std;

int maxThread;
int N;

void enter(int &temp)
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

void multiParallel(Matrix A, Matrix B, Matrix &C, int temp)
{
    int i = temp;
    while (i<N)
    {
        for (int j=0; j<N; j++)
        {
            C.arr[i][j] = 0;
            for (int k=0; k<N; k++)
                C.arr[i][j] += A.arr[i][k] * B.arr[k][j];
        }
        i += maxThread;
    }
}

void multiStandart(Matrix A, Matrix B, Matrix &C)
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            C.arr[i][j] = 0;
                for (int k=0; k<N; k++)
                    C.arr[i][j] += A.arr[i][k] * B.arr[k][j];
        }
}

void menu(){
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
        std::cout<<"11 - Run GoogleTests"<<std::endl;
        std::cout<<"12 - Exit"<<std::endl;
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

        }
        else if (temp == 8)
        {
            std::cout<<"Matrix B"<<std::endl;
            matrixB.display();
        }
        else if (temp == 9)
        {
            std::thread threads[maxThread];
            auto begin = std::chrono::steady_clock::now();
            for (int i=0; i<maxThread; i++)
                threads[i] = std::thread(multiParallel, matrixA, matrixB, std::ref(matrixC), i);
            for (int i=0; i<maxThread; i++)
                threads[i].join();
            auto end = std::chrono::steady_clock::now();

            std::cout<<"Parallel algorithm :"<<std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<" microseconds"<<std::endl;


            begin = std::chrono::steady_clock::now();
            multiStandart(matrixA, matrixB, matrixC);
            end = std::chrono::steady_clock::now();

            std::cout<<"Standart algorithm :"<<std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()<<" microseconds"<<std::endl;
        }
        else if (temp == 10)
        {
            std::cout<<"Matrix C"<<std::endl;
            matrixC.display();
        }
        else if (temp == 11)
        {

        }
        else if (temp == 12)
        {
            return;
        }
    }
}

int main() {
    srand(time(0));

    menu();
    return 0;
}