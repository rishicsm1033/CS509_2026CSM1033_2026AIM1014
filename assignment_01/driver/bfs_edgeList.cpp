#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void bfsEdgeList(vector<int>& source,vector<int>& dest,int n,int v){
    queue<int> que;
    unordered_set<int> visited;

    // cout<<"Enter the node where you start bfs traversal : ";
    

    que.push(v);
    visited.insert(v);

    while(!que.empty()){
        int currNode = que.front();
        que.pop();

        // cout<<currNode<<"->";
        for(int i=0;i<n;i++){
            if(source[i] == currNode ){
                int neighbor = dest[i];
                if(visited.find(neighbor) == visited.end()){
                    visited.insert(neighbor);
                    que.push(neighbor);
                }
            }
        }
    }
    // cout<<"NULL";

}