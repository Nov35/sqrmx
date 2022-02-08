#ifndef SQRMX_H
#define SQRMX_H

#include <sstream>
class SqrMx {
    int* m_arr;
    int  m_arr_s;
public:
    SqrMx(int n);
    int* col_sum();
    int* row_sum();
    void tranpose();
    int* operator[](int i) const;
    SqrMx& operator+=(const SqrMx &oth);
    SqrMx& operator*=(const SqrMx &oth);
    SqrMx& overload_acc_mul(const SqrMx &oth);
    SqrMx& operator-=(const SqrMx &oth);
    friend std::ostream& operator<<(std::ostream &out, SqrMx &obj);
    ~SqrMx(){
        delete [] m_arr;
    }
};
#endif
