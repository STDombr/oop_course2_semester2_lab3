#include <iostream>
#include <string>
#include "Matrix.h"
#include <gtest/gtest.h>

class MatrixTest : public ::testing::Test{
protected:
    virtual void SetUp(){
        M0 = new Matrix(0);
        M1 = new Matrix(4);
    }

    Matrix *M0, *M1;
};

TEST_F(MatrixTest, ValidConstructor) {
    EXPECT_EQ(0,M0->getN());
    EXPECT_EQ(0,M0->arr.size());
    EXPECT_EQ(4,M1->arr.size());
    for (auto j = 0; j < M1->getN(); j++)
        EXPECT_EQ(4,M1->arr[j].size());
}

TEST_F(MatrixTest, IsEmpty) {
    for (auto i = 0; i < M1->getN(); i++)
        for (auto j = 0; j < M1->getN(); j++)
            EXPECT_EQ(0,M1->arr[i][j]);
}

TEST_F(MatrixTest, ValidMultiply) {
    int n = rand()%1000;
    Matrix M2(n), M3(n), res1(n), res2(n);
    M2.random();
    M3.random();

    res1.multiply(M2,M3);
    res2.multiplyParallel(M2,M3);

    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            EXPECT_EQ(res1.arr[i][j],res2.arr[i][j]);
}

TEST(TimeTest, Test1)
{
    int n = 10;
    Matrix M2(n), M3(n), res1(n), res2(n);
    M2.random();
    M3.random();

    long long int time1 = res1.multiply(M2,M3);
    long long int time2 = res2.multiplyParallel(M2,M3);

    std::cout<<"======================================================="<<std::endl;
    std::cout<<"Matrix "<<n<<"*"<<n<<std::endl;
    std::cout<<"Parallel algorithm :"<<time2<<" microseconds"<<std::endl;
    std::cout<<"Standart algorithm :"<<time1<<" microseconds"<<std::endl;
    std::cout<<"======================================================="<<std::endl;
}

TEST(TimeTest, Test2)
{
    int n = 100;
    Matrix M2(n), M3(n), res1(n), res2(n);
    M2.random();
    M3.random();

    long long int time1 = res1.multiply(M2,M3);
    long long int time2 = res2.multiplyParallel(M2,M3);

    std::cout<<"======================================================="<<std::endl;
    std::cout<<"Matrix "<<n<<"*"<<n<<std::endl;
    std::cout<<"Parallel algorithm :"<<time2<<" microseconds"<<std::endl;
    std::cout<<"Standart algorithm :"<<time1<<" microseconds"<<std::endl;
    std::cout<<"======================================================="<<std::endl;
}

TEST(TimeTest, Test3)
{
    int n = 1000;
    Matrix M2(n), M3(n), res1(n), res2(n);
    M2.random();
    M3.random();

    long long int time1 = res1.multiply(M2,M3);
    long long int time2 = res2.multiplyParallel(M2,M3);

    std::cout<<"======================================================="<<std::endl;
    std::cout<<"Matrix "<<n<<"*"<<n<<std::endl;
    std::cout<<"Parallel algorithm :"<<time2<<" microseconds"<<std::endl;
    std::cout<<"Standart algorithm :"<<time1<<" microseconds"<<std::endl;
    std::cout<<"======================================================="<<std::endl;
}

/*TEST(TimeTest, Test4)
{
    int n = 10000;
    Matrix M2(n), M3(n), res1(n), res2(n);
    M2.random();
    M3.random();

    long long int time1 = res1.multiply(M2,M3);
    long long int time2 = res2.multiplyParallel(M2,M3);

    std::cout<<"Matrix "<<n<<"*"<<n<<std::endl;
    std::cout<<"Parallel algorithm :"<<time2<<" microseconds"<<std::endl;
    std::cout<<"Standart algorithm :"<<time1<<" microseconds"<<std::endl;
}*/