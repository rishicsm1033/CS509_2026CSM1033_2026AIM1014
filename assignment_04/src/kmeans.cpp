#include <iostream>
#include <vector>
#include <iomanip>
#include<chrono>
#include "../src/kmeans.h"
using namespace std;
int main()
{
    int N;
    int D;
    int K;
    cin >> N >> D >> K;
    // Read N points
    vector<vector<double>> points(N,vector<double>(D));
    for (int i = 0; i < N; i++)
    {
        for (int d = 0; d < D; d++)
        {
            cin >> points[i][d];
        }
    }
    int max_iterations;
    cin >> max_iterations;
    double tolerance;
    cin >> tolerance;

    auto start=chrono::high_resolution_clock::now();
    KMeansResult result =kmeans(points,K,max_iterations,tolerance);
    auto end=chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout << "\nFinal Centroids:\n";
    cout << fixed << setprecision(6);
    for (int k = 0; k < K; k++)
    {
        cout << "Cluster " << k<< ": ";
        for (int d = 0; d < D; d++)
        {
            cout << result.centroids[k][d];
            if (d != D - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    // Print cluster size
    cout << "\nCluster Sizes:\n";
    vector<int> cluster_size(K, 0);
    for (int i = 0; i < N; i++)
    {
        cluster_size[result.cluster[i]]++;
    }
    for (int k = 0; k < K; k++)
    {
        cout << "Cluster " << k<< ": "<< cluster_size[k]<< endl;
    }
    cout << "wcss" << result.wcss << " "<< endl;
     cout << "Iterations: "<< result.iterations<< endl;
    bool converged=result.iterations < max_iterations;
    cout<< "converged : " << (converged ? "true" : "false") << endl ;
    cout<< "run time complexity" <<  time << " ms ";
        return 0;
}