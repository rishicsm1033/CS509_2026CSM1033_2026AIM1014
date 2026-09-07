#ifndef FASTMAP_H
#define FASTMAP_H

#include <vector>
#include <utility>

class FastMap {
private:
    int N;
    int K;
    std::vector<std::vector<double>> orig_dist;
    std::vector<std::vector<double>> coordinates;

    // Internal geometric helper methods
    double get_squared_dist(int i, int j, int current_dim) const;
    std::pair<int, int> choose_pivots(int current_dim) const;

public:
    FastMap(int n,int k,const std::vector<std::vector<double>>& distances);

    void computeEmbeddings();


    const std::vector<std::vector<double>>& getCoordinates() const;
    int getTargetDimensions() const;
    int getObjectCount() const;
};

#endif 
