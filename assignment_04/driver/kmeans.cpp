#include "../src/kmeans.h"
#include <cmath>
#include <limits>
using namespace std;
// Calculate squared Euclidean distance
double squaredDistance(const vector<double>& a,const vector<double>& b)
{
    double distance = 0.0;
    for (int d = 0; d < (int)a.size(); d++)
    {
        double diff = a[d] - b[d];
        distance += diff * diff;
    }
    return distance;
}
// Main K-Means function
KMeansResult kmeans(const vector<vector<double>>& points,int K,int max_iterations,double tolerance)
{
    int N = points.size();
    int D = points[0].size();
    // Step 1: Initialize K centroids
    // First K points are used as centroids
    vector<vector<double>> centroids(K, vector<double>(D));
    for (int k = 0; k < K; k++)
    {
        centroids[k] = points[k];
    }
    // Cluster assigned to every point
    vector<int> cluster(N, -1);
    int iterations = 0;
    // Repeat until convergence or max iterations
    for (int iteration = 0;iteration < max_iterations;iteration++)
    {
        iterations++;
        // Step 2: Assignment step
        bool changed = false;
        for (int i = 0; i < N; i++)
        {
            double min_distance =numeric_limits<double>::max();
            int best_cluster = 0;
            // Find nearest centroid
            for (int k = 0; k < K; k++)
            {
                double distance =squaredDistance(points[i], centroids[k]);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    best_cluster = k;
                }
            }
            // Check whether assignment changed
            if (cluster[i] != best_cluster)
            {
                changed = true;
            }
            cluster[i] = best_cluster;
        }
        // Step 3: Update step
        vector<vector<double>> new_centroids(K,vector<double>(D, 0.0));
        vector<int> count(K, 0);
        // Add every point to its cluster sum
        for (int i = 0; i < N; i++)
        {
            int k = cluster[i];
            count[k]++;
            for (int d = 0; d < D; d++)
            {
                new_centroids[k][d] += points[i][d];
            }
        }
        // Calculate mean
        for (int k = 0; k < K; k++)
        {
            if (count[k] == 0)
            {
                // Empty cluster:
                // keep previous centroid unchanged
                new_centroids[k] = centroids[k];
            }
            else
            {
                for (int d = 0; d < D; d++)
                {
                    new_centroids[k][d] /= count[k];
                }
            }
        }
        // Step 4: Calculate maximum centroid shift
        double max_shift = 0.0;
        for (int k = 0; k < K; k++)
        {
            double shift = 0.0;
            for (int d = 0; d < D; d++)
            {
                double diff =new_centroids[k][d]- centroids[k][d];
                shift += diff * diff;
            }
            // Euclidean centroid shift
            shift = sqrt(shift);
            if (shift > max_shift)
            {
                max_shift = shift;
            }
        }
        // Replace old centroids
        centroids = new_centroids;
        // Step 5: Check convergence
        if (!changed || max_shift <= tolerance)
        {
            break;
        }
    }
    double wcss = 0.0;
    for (int i = 0; i < N; i++)
    {
        int k = cluster[i];
        wcss += squaredDistance( points[i],centroids[k] );
    }
    // Return result
    KMeansResult result;
    result.centroids = centroids;
    result.cluster = cluster;
    result.iterations = iterations;
    result.wcss=wcss;
    
    return result;
}