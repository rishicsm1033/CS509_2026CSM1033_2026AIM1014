#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Define a structural object representing an Edge
struct Edge {
    int src;
    int dest;
    int weight;
};

// Updated declaration to accept a vector of Edge structures
void ssspath(const vector<Edge>& edges_list, int nodes, int edges, int start_node);

int main() {
    int edges, nodes;
    // cout << "Enter the no. of nodes: ";
    cin >> nodes;
    cout << endl;
    // cout << "Enter the no. of edges: ";
    cin >> edges;
    cout << endl;

    // A single unified vector holding Edge objects
    vector<Edge> edges_list(edges);

    // cout << "Enter source, destination, and weight for each edge (e.g., 0 1 5):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> edges_list[i].src >> edges_list[i].dest >> edges_list[i].weight;
    }

    int start_node;
    // cout << "Enter the source node: ";
    cin >> start_node;

    auto start = chrono::high_resolution_clock::now();
    ssspath(edges_list, nodes, edges, start_node);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;

    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl; 
    return 0;
}
