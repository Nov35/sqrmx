#include <iostream>
#include "timer.h"
#include "sqrmx.h"

void print_arr(int *arr, int s);

int main()
{
    int *res, size = 1024;
    srand(0);
    SqrMx x(size), y(size);
    std::cout.setf(std::ios::fixed);
#ifdef PRINT
    std::cout << x;
#endif

    Timer t;
    res = x.col_sum();
    std::cout << "Column summation has took " << t.get() << " seconds.\n";
#ifdef PRINT
    print_arr(res, s);
#endif
    t.reset();
    res = x.row_sum();
    std::cout << "Row summation has took " << t.get() << " seconds.\n";
#ifdef PRINT
    print_arr(res, s);
#endif

    t.reset();
    x.tranpose();
    std::cout << "Transposition has took " << t.get() << " seconds.\n";
#ifdef PRINT
    std::cout << x;
#endif

    t.reset();
    x+=y;
    std::cout << "Addition has took " << t.get() << " seconds.\n";
#ifdef PRINT
    std::cout << x;
#endif

    t.reset();
    x*=y;
    std::cout << "Multiplication has took " << t.get() << " seconds.\n";
#ifdef PRINT
    std::cout << x;
#endif

    t.reset();
    x.overload_acc_mul(y);
    std::cout << "Multiplication with overloaded array acces operator has" <<
        " took " << t.get() << " seconds.\n";

    t.reset();
    x-=y;
    std::cout << "Substraction has took " << t.get() << " seconds.\n";
#ifdef PRINT
    std::cout << x;
#endif
    
    int unInitVar;
    for(int i = 0; i < 10; i++) //Example of incorrect code that can be detected
        unInitVar += i;         //with Valgrind, but not with compiler
}

void print_arr(int *arr, int s)
{
    for(int i = 0; i < s; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}
