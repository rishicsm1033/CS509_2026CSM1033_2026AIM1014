#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Redefine the exact same struct signature so this file recognizes the layout
struct Edge {
    int src;
    int dest;
    int weight;
};

void path(int curr_node, const vector<int>& parent){
    if(curr_node == -1){
        return;
    }
    path(parent[curr_node], parent);
    cout << curr_node << "->";
}

void ssspath(const vector<Edge>& edges_list, int nodes, int edges, int start_node){

    // Strict boundary verification logic
    if (start_node < 0 || start_node >= nodes) {
        cout << "\n[ERROR] Source node " << start_node 
             << " is out of bounds! Valid nodes are 0 to " << nodes - 1 << "." << endl;
        return; 
    }

    vector<int> dist(nodes, INT_MAX);
    vector<int> parent(nodes, -1);

    dist[start_node] = 0;

    // Min-Priority Queue stores pairs of (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start_node});

    while(!pq.empty()){
        int curr_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(curr_dist > dist[u]){
            continue;
        }

        // Direct lookup matching nodes directly inside our structural layout
        for(int i = 0; i < edges; i++){
            if(edges_list[i].src == u){ 
                int v = edges_list[i].dest;
                int w = edges_list[i].weight;

                if (v < 0 || v >= nodes) {
                    continue; 
                }

                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // Print operational path trace updates
    // cout << "\nShortest paths from source node (" << start_node << "):" << endl;
    // for(int i = 0; i < nodes; i++) {
    //     cout << "Node " << i << " : ";
    //     if(dist[i] == INT_MAX) {
    //         cout << "Distance = INF | Path = Unreachable" << endl;
    //     } else {
    //         cout << "Distance = " << dist[i] << " | Path = ";
    //         path(i, parent);
    //         cout << "End" << endl;
    //     }
    // }
}
