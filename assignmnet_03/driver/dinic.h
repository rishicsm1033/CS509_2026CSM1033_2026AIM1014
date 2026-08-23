#ifndef DINIC_H
#define DINIC_H

#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;


struct Edge {
    int to;
    int capacity;
    int rev; 
};

class Dinic {
    int n;
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> ptr;

public:
    Dinic(int n) {
        this->n = n;
        graph.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void addEdge(int u, int v, int capacity) {
        Edge forward = {v, capacity, (int)graph[v].size()};
        Edge backward = {u, 0, (int)graph[u].size()};
        graph[u].push_back(forward);
        graph[v].push_back(backward);
    }

    bool bfs(int source, int sink) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(source);
        level[source] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &edge : graph[u]) {
                if (edge.capacity > 0 && level[edge.to] == -1) {
                    level[edge.to] = level[u] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int u, int sink, int flow) {
        if (u == sink) return flow;

        for (int &i = ptr[u]; i < graph[u].size(); i++) {
            Edge &edge = graph[u][i];
            if (edge.capacity > 0 && level[edge.to] == level[u] + 1) {
                int pushed = dfs(
                    edge.to, 
                    sink, 
                    min(flow, edge.capacity)
                );
                if (pushed > 0) {
                    edge.capacity -= pushed;
                    graph[edge.to][edge.rev].capacity += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int maxFlow(int source, int sink) {
        int totalFlow = 0;
        while (bfs(source, sink)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(source, sink, INT_MAX)) {
                totalFlow += pushed;
            }
        }
        return totalFlow;
    }
};

#endif 
