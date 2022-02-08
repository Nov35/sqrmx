#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <iostream>

class Timer {
    using cl_t = std::chrono::high_resolution_clock;
    using sec_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<cl_t> start;
public:
    Timer() : start(cl_t::now()) {}
    void reset(){
	start = cl_t::now();
    }
    double get(){
    	 return std::chrono::duration_cast<sec_t>(cl_t::now() - start).count();
    }
};
#endif
