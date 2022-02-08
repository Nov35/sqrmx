#ifndef SQRMX_H
#define SQRMX_H

class SqrMx {
    int* m_arr;
public:
    SqrMx();
    int* get() { return m_arr; }
    void col_sum();
    void row_sum();
    void tranpose();
    SqrMx& operator+=(const SqrMx &oth);
    SqrMx& operator*=(const SqrMx &oth);
    SqrMx& operator-=(const SqrMx &oth);
    ~SqrMx(){
        delete [] m_arr;
    }
};
#endif
