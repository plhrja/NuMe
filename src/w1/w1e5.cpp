/* 
 * File:   w1e5.cpp
 * Author: Lasse Lybeck
 *
 * Created on January 4, 2014, 3:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <gsl/gsl_precision.h>
#include <cmath>

const double eps = gsl_prec_sqrt_eps[0];
const double max_iter = 50;

using namespace std;

double fixed_point_iteration(double (*f)(double)) {
    double x = 0;
    double oldx;
    for (int i = 1; i <= max_iter; i++) {
        oldx = x;
        x = f(x);
        if(abs(x - oldx) < eps)
            break;
        if(i == max_iter)
            cout << "WARNING! Maximum number of iterations reached in fixed point iteration,"
                    " the iteration might not have converged!" << endl;
    }
    return x;
}

/*
 * 
 */
int main(int argc, char** argv) {

    double a = fixed_point_iteration(&cos);
    double b = fixed_point_iteration([] (double x) {return exp(-x);});
    double c = fixed_point_iteration([] (double x) {return 1 - cosh(x);});

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
