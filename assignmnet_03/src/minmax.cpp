#include <iostream>
#include <chrono>
#include "../drive/dinic.h"

using namespace std;

int main() {
    int numVertices, numEdges;

    
    //cout << "Enter total number of vertices: ";
    cin >> numVertices;
    
    //cout << "Enter total number of edges: ";
    cin >> numEdges;

    Dinic dinic(numVertices);

   // cout << "\nEnter each edge details format: [source] [destination] [capacity]" << endl;
    //cout << "(Note: Vertices should be between 0 and " << numVertices - 1 << ")" << endl;
    
    for (int i = 0; i < numEdges; ++i) {
        int u, v, capacity;
        // cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> capacity;
        
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            dinic.addEdge(u, v, capacity);
        } else {
            // cout << "Invalid vertex indices! Please enter indices between 0 and " << numVertices - 1 << ".\n";
            i--;
        }
    }

    int source, sink;
    //cout << "\nEnter the source vertex index: ";
    cin >> source;
    //cout << "Enter the sink vertex index: ";
    cin >> sink;

    //cout << "\nRunning Dinic's Algorithm..." << endl;
    auto start = chrono::high_resolution_clock::now();
    
    int max_flow = dinic.maxFlow(source, sink);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << "--------------------------------------------" << endl;
    cout << "Maximum Flow: " << max_flow << endl;
    cout << "Execution Time: " << duration.count() << " ms" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}
