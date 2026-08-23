#include"../src/gradient_descent.h"
#include<cmath>
using namespace std;
double evaluatepolynomial(const vector<double>& coefficients,double x)
{
    double result=0.0;
    int degree = coefficients.size() -1 ;
    for(int i=0;i<=degree;i++)
    {
        result+=coefficients[i]*pow(x,degree-i);
    }
    return result;
}

double evaluatederivative(const vector<double>& coefficients,double x)
{
    double derivative=0.0;
    int degree = coefficients.size() -1 ;
    for(int i=0;i<degree;i++)
    {
        int power =degree -i;
        derivative+= power*coefficients[i] *pow(x,power-1);   
    }
    return derivative;
}

Result gradientdescent(const vector<double> &coefficients,double initial_x,double learning_rate,double tolerance,int iterations)
{
    double x=initial_x;
    bool converged=false;
    int i;
    for(i=0;i<iterations;i++)
    {
        double derivative=evaluatederivative(coefficients,x);
        if(fabs(derivative) <= tolerance)
        {
            converged = true;
            break;
        }
        x=x-learning_rate*derivative;
    }
    Result result;
    result.final_x=x;
    result.final_fx=evaluatepolynomial(coefficients,x);
    result.iterations=i;
    result.converged= converged;
    return result;
}