#include<iostream>
#include<vector>
#include<iomanip>
#include"../src/gradient_descent.h"
#include<chrono>
using namespace std;
int main()
{
    int degree;
    cin>>degree;
    vector<double> coefficients(degree+1);
    for(int i=0;i<=degree;i++)
    {
        cin >> coefficients[i];
    }
    double initial_x;
    double learning_rate;
    double tolerance;
    int iterations;

    cin >>initial_x;
    cin>>learning_rate;
    cin>>tolerance;
    cin>>iterations;

    auto start=chrono::high_resolution_clock::now();
    Result result=gradientdescent(coefficients, initial_x, learning_rate, tolerance, iterations);
    auto end=chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    
     cout<<"degree : " << degree<< endl;
     cout<< "final x : " << result.final_x<<endl;
     cout<< "final f(x) : " << result.final_fx<<endl;
     cout<<" iterations : " <<result.iterations<<endl;
     cout<<"execution time : "<< time<<endl;
     return 0;
}