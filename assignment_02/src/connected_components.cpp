#include <iostream>
#include <vector>
#include <chrono>
#include "edge_list.h"

using namespace std;
void connectedComponents(vector<vector<int>>& ans,vector<edgeList>& edges,int e,int v);
int main(){
    int v;
    cout<<"Enter the no.of vertices : ";
    cin>>v;

    int e;
    cout<<"Enter the no.of edges : ";
    cin>>e;

    vector<edgeList> edges;
    cout<<"Enter the edges :(src,dest,weight) "<<endl;
    for(int i=0;i<e;i++){
        edgeList temp;
        cin>>temp.src>>temp.dest>>temp.weight;
        edges.push_back(temp);
    }

    vector<vector<int>> ans;
     auto start = chrono::high_resolution_clock::now();
    connectedComponents(ans,edges,e,v);
    auto end = chrono::high_resolution_clock::now();

    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    

    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(auto vertex : ans[i]){
            cout<<vertex<<" ";
        }
        cout<<"]";
    }
    cout<<"]";


    
    return 0;
}