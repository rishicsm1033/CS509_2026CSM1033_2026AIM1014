#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H
#include<vector>
using namespace std;
struct Result
{
    double final_x;
    double final_fx;
    int iterations;
    bool converged;
};
Result gradientdescent(const vector<double> &coefficients,double initial_x,double learning_rate,double tolerance,int iterations);

#endif
