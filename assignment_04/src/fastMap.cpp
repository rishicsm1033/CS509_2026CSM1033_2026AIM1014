#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../driver/fastMap.h"

using namespace std;

int main() {
    // Fast I/O channels for scaling up execution performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<vector<double>> input_matrix(N, vector<double>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input_matrix[i][j];
        }
    }

    // Instantiation and timing benchmark window
    auto start = chrono::high_resolution_clock::now();
    
    FastMap mapper(N, K, input_matrix);
    mapper.computeEmbeddings();
    
    auto end = chrono::high_resolution_clock::now();
    double exec_time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    // Streaming Formatted Matrix Output
    cout << fixed << setprecision(6);
    cout << "Algorithm: FastMap\n";
    cout << "Target Dimensions : " << mapper.getTargetDimensions() << "\n\n";
    cout << "Projected coordinates : (NxK)\n";

    const auto& coordinates = mapper.getCoordinates();
    for (int i = 0; i < N; i++) {
        cout << i << " : ";
        for (int m = 0; m < K; m++) {
            cout << coordinates[i][m] << ((m == K - 1) ? "" : " ");
        }
        cout << "\n"; // Escaping std::endl optimizes execution bounds considerably
    }

    cout << "=======================================\n";
    cout << "||   Executed Time : " << exec_time << " ms       ||\n";
    cout << "=======================================\n";

    return 0;
}
