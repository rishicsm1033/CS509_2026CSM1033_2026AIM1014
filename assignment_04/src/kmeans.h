#ifndef KMEANS_H
#define KMEANS_H
#include <vector>
using namespace std;
struct KMeansResult
{
    vector<vector<double>> centroids;
    vector<int> cluster;
    int iterations;
    double wcss;
};
KMeansResult kmeans(const vector<vector<double>>& points,int K,int max_iterations,double tolerance);
#endif