#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

#include "../src/edge_list.h"

using namespace std;

void dfs(vector<edgeList>& edges,set<int>& visited,int source,vector<vector<int>>& ans){
    stack<int> st;
    st.push(source);

    vector<int> result;

    while(!st.empty()){
        int curr_node = st.top();
        st.pop();

        if(!visited.contains(curr_node)){
            result.push_back(curr_node);
            visited.insert(curr_node);
            for(auto edge : edges){
                int neighbour = -1;
                
                if(edge.src==curr_node){
                    neighbour = edge.dest;
                }
                else if(edge.dest == curr_node){
                    neighbour = edge.src;
                }
                if(neighbour!=-1 && !visited.contains(neighbour)){
                    st.push(neighbour);
                }
            }
        }
    }
    ans.push_back(result);
    return;


}


void bfs(vector<edgeList>& edges,set<int>& visited,int source,vector<vector<int>>& ans){
    queue<int> que;
    visited.insert(source);
    que.push(source);
    
    vector<int> result;
    

    while(!que.empty()){
        int curr_node = que.front();
        que.pop();
        result.push_back(curr_node);

        for(auto edge : edges){
            int neighbour = -1;
            if(edge.src == curr_node){
                neighbour = edge.dest;
            }else if(edge.dest == curr_node){
                neighbour = edge.src;
            }

            if(neighbour!=-1 && !visited.contains(neighbour)){
                que.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    ans.push_back(result);
    return;
}

void connectedComponents(vector<vector<int>>& ans,vector<edgeList>& edges,int e,int v){
    
    set<int> visited;
    for(int i=0;i<v;i++){
        if(!visited.contains(i)){
            dfs(edges,visited,i,ans);
        }
    }
}