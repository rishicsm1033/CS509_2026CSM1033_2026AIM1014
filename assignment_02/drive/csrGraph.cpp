#include <iostream>
#include <vector>
using namespace std;


void csrGraph(vector<vector<pair<int,int>>>& adjList, vector<int>& vertex, vector<int>& child, vector<int>& weight, int v) {
    vector<int> degree(v, 0);
    for(int i=0;i<v;i++) {
        degree[i]=adjList[i].size();
    }
    vertex[0]=0;
    for(int i=0;i<v;i++) {
        vertex[i+1]=vertex[i]+degree[i];
    }

    
    for(int i=0;i<v;i++) {
        int currentChildIndex = vertex[i]; 
        for(auto& edge : adjList[i]) {
            child[currentChildIndex] = edge.first;     // Destination vertex
            weight[currentChildIndex] = edge.second;   // Edge weight
            currentChildIndex++;
        }
    }
}