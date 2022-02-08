#include "sqrmx.h"
#include <cstdlib>
#include <iostream>

const int arr_s = 1024;

SqrMx::SqrMx()
{
    m_arr = new int [arr_s * arr_s];
    for(int i = 0; i < arr_s; i++)
        m_arr[i] = rand();
}

void SqrMx::col_sum()
{
    int* res = new int[arr_s]; // The located with this pointed won't be
                               // freed for an example of using Valgrind
    for(int i = 0; i < arr_s * arr_s; i += arr_s){
        res[i/arr_s] = 0;
        for(int j = 0; j < arr_s; j++)
            res[i/arr_s] += m_arr[i + j];
    }
}

void SqrMx::row_sum()
{
    int* res = new int[arr_s];
    for(int i = 0; i < arr_s; i++){
        res[i] = 0;
        for(int j = 0; j < arr_s * arr_s; j+=arr_s){
            res[i] += m_arr[i + j];
        }
    }
    delete[] res;
}

void SqrMx::tranpose()
{
    int* res = new int[arr_s * arr_s];
    for(int i = 0; i < arr_s; i++)
        for(int j = 0; j < arr_s; j++)
            res[i*arr_s + j] = m_arr[j*arr_s + i];
    int* tmp = m_arr;
    m_arr = res;
    delete[] tmp;
}

SqrMx& SqrMx::operator+=(const SqrMx &oth)
{
    for(int i = 0; i < arr_s * arr_s; i++)
        m_arr[i] += oth.m_arr[i];
    return *this;
}

SqrMx& SqrMx::operator*=(const SqrMx &oth)
{
    long long n = arr_s;
    int *res = new int[n * n]; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            res[i*n + j] = 0;
            for(int k = 0; k < n; k++)
                res[i*n + j] += m_arr[i*n + k] * oth.m_arr[k*n + j];
        }
    int* tmp = m_arr;
    m_arr = res;
    delete[] tmp;
    return *this;
}

SqrMx& SqrMx::operator-=(const SqrMx &oth)
{
    for(int i = 0; i < arr_s * arr_s; i++)
        m_arr[i] -= oth.m_arr[i];
    return *this;
}
