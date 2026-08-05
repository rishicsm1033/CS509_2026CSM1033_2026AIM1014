#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;
void dfsEdgeList(vector<int>& source,vector<int>& dest,int n,int v){

    stack<int> s;
    unordered_set<int> visited;

    // cout<<"Enter the node where you start dfs traversal : ";
    // int node;
    // cin>>node;
    s.push(v);
    while(!s.empty()){

        int curr_node = s.top();
        s.pop();

        if(visited.find(curr_node)==visited.end()){
            // cout<<curr_node<<"->";
            visited.insert(curr_node);

            for(int i=n-1;i>=0;i--){
                if(source[i] == curr_node){
                    s.push(dest[i]);
                }
            }
        }
    }
    // cout<<"NULL";
}