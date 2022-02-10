#include "sqrmx.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <ostream>

SqrMx::SqrMx(int n) : m_arr_s(n)
{
    m_arr = new int [m_arr_s * m_arr_s];
    for(int i = 0; i < m_arr_s * m_arr_s; i++)
        m_arr[i] = rand();
}

int* SqrMx::col_sum()
{
    int* res = new int[m_arr_s]; //This pointer will not be freed
    for(int i = 0; i < m_arr_s; i ++){
        res[i] = 0;
        for(int j = 0; j < m_arr_s; j++)
            res[i] += m_arr[i*m_arr_s + j];
    }
    return res;
}

int* SqrMx::row_sum()
{
    int* res = new int[m_arr_s]; //This pointer will not be freed
    for(int i = 0; i < m_arr_s; i++){
        res[i] = 0;
        for(int j = 0; j < m_arr_s; j++){
            res[i] += m_arr[i + j*m_arr_s];
        }
    }
    return res;
}

void SqrMx::tranpose()
{
    int* res = new int[m_arr_s * m_arr_s];
    for(int i = 0; i < m_arr_s; i++)
        for(int j = 0; j < m_arr_s; j++)
            res[i*m_arr_s + j] = m_arr[j*m_arr_s + i];
    int* tmp = m_arr;
    m_arr = res;
    delete[] tmp;
}

int* SqrMx::operator[](int i) const
{
    assert((i >= 0 && i < m_arr_s) && "Incorrect index");
    return m_arr + i*m_arr_s;
}

SqrMx& SqrMx::operator+=(const SqrMx &oth)
{
    int size = m_arr_s < oth.m_arr_s ? m_arr_s : oth.m_arr_s;
    for(int i = 0; i < size * size; i++)
        m_arr[i] += oth.m_arr[i];
    return *this;
}

SqrMx& SqrMx::operator*=(const SqrMx &oth)
{
    assert(m_arr_s == oth.m_arr_s && "Matrixes have different size!");
    long long n = m_arr_s;
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

SqrMx& SqrMx::overload_acc_mul(const SqrMx &oth)
{
    assert(m_arr_s == oth.m_arr_s && "Matrixes have different size!");
    long long n = m_arr_s;
    int *res = new int[n * n]; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            res[i*n + j] = 0;
            for(int k = 0; k < n; k++)
                res[i*n + j] += (*this)[i][k] * oth[k][j];
        }
    int* tmp = m_arr;
    m_arr = res;
    delete[] tmp;
    return *this;
}

SqrMx& SqrMx::operator-=(const SqrMx &oth)
{
    int size = m_arr_s < oth.m_arr_s ? m_arr_s : oth.m_arr_s;
    for(int i = 0; i < size * size; i++)
        m_arr[i] -= oth.m_arr[i];
    return *this;
}

std::ostream& operator<<(std::ostream &out, SqrMx &obj)
{
    for(int i = 0; i < obj.m_arr_s; i++){
        for(int j = 0; j < obj.m_arr_s; j++)
            out << obj.m_arr[i*obj.m_arr_s + j] << ' ';
        out << '\n';
    }
    return out;
}
