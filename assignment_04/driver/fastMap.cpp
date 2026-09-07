#include "fastMap.h"
#include <cmath>
#include <algorithm>

FastMap::FastMap(int n, int k, const std::vector<std::vector<double>>& distances) 
    : N(n), K(k), orig_dist(distances) {
    coordinates.assign(N, std::vector<double>(K, 0.0));
}

double FastMap::get_squared_dist(int i, int j, int current_dim) const {
    if (i == j) return 0.0;

    double sq_dist = orig_dist[i][j] * orig_dist[i][j];

    for (int m = 0; m < current_dim; m++) {
        double diff = coordinates[i][m] - coordinates[j][m];
        sq_dist -= diff * diff;
    }

    return std::max(0.0, sq_dist);
}

std::pair<int, int> FastMap::choose_pivots(int current_dim) const {
    int pivot_a = 0;
    int pivot_b = 0;
    double max_dist = -1.0;

    for (int i = 0; i < N; i++) {
        double d2 = get_squared_dist(pivot_a, i, current_dim);
        if (d2 > max_dist) {
            max_dist = d2;
            pivot_b = i;
        }
    }

    pivot_a = pivot_b;
    max_dist = -1.0;
    
    for (int i = 0; i < N; i++) {
        double d2 = get_squared_dist(pivot_a, i, current_dim);
        if (d2 > max_dist) {
            max_dist = d2;
            pivot_b = i;
        }
    }
    return {pivot_a, pivot_b};
}

void FastMap::computeEmbeddings() {
    for (int m = 0; m < K; m++) {
        auto [O_a, O_b] = choose_pivots(m);

        double dab_sq = get_squared_dist(O_a, O_b, m);
        double dab = std::sqrt(dab_sq);

        if (dab < 1e-9) {
            for (int i = 0; i < N; i++) {
                coordinates[i][m] = 0.0;
            }
            continue;
        }

        for (int i = 0; i < N; i++) {
            if (i == O_a) {
                coordinates[i][m] = 0.0;
            }
            else if (i == O_b) {
                coordinates[i][m] = dab;
            }
            else {
                double dai_sq = get_squared_dist(O_a, i, m);
                double dbi_sq = get_squared_dist(O_b, i, m);
                double xi = (dai_sq + dab_sq - dbi_sq) / (2.0 * dab);
                coordinates[i][m] = xi;
            }
        }
    }
}

const std::vector<std::vector<double>>& FastMap::getCoordinates() const {
    return coordinates;
}

int FastMap::getTargetDimensions() const {
    return K;
}

int FastMap::getObjectCount() const {
    return N;
}
