#include <iostream>
#include "timer.h"
#include "sqrmx.h"

int main()
{
    srand(0);
    SqrMx x, y;
    std::cout.setf(std::ios::fixed);

    Timer t;
    x.col_sum();
    std::cout << "Column summation has took " << t.get() << " seconds.\n";

    t.reset();
    x.row_sum();
    std::cout << "Row summation has took " << t.get() << " seconds.\n";

    t.reset();
    x.tranpose();
    std::cout << "Transposition has took " << t.get() << " seconds.\n";

    t.reset();
    x+=y;
    std::cout << "Addition has took " << t.get() << " seconds.\n";

    t.reset();
    x*=y;
    std::cout << "Multiplication has took " << t.get() << " seconds.\n";

    t.reset();
    x-=y;
    std::cout << "Substraction has took " << t.get() << " seconds.\n";
    int unInitVar;
    for(int i = 0; i < 10; i++) //Example of incorrect code that can be detected
        unInitVar += i;         //with Valgrind, but not with compiler
}
