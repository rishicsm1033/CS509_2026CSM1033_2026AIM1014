#include <iostream>
#include <vector>
#include "edge_list.h"
#include <chrono>
using namespace std;


void betweenness(int v,int e,vector<edgeList>& edges);
int main(){
    int v;
    cout<< "Enter the no.of vertices : ";
    cin>>v;
    cout<<endl;

    int e;
    cout<<"Enter the no.of edges :";
    cin>>e;
    cout<<endl;

    cout<<"source destination weight";
    vector<edgeList> edges(e);
    for(int i=0;i<e;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }
     auto start = chrono::high_resolution_clock::now();
    betweenness(v,e,edges);
    auto end = chrono::high_resolution_clock::now();

    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl; 
    
    return 0;

}