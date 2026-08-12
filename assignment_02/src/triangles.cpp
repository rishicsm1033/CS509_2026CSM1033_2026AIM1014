#include <iostream>
#include <vector>
#include <chrono>
#include "edge_list.h"

using namespace std;
int triangleCount(vector<int>& row_ptr, vector<int>& col,int v, int e);
int main(){
    int v;
    cout<<"Enter the no.of vertices : ";
    cin>>v;

    int e;
    cout<<"Enter the no.of Edges : ";
    cin>>e;

    // vector<int> row_ptr(v+1,0);
    // vector<int> col(2*e);

    // cout<<"Enter the row_ptr values : "<<endl;
    // for(int i=0;i<=v;i++){
    //     cin>>row_ptr[i];
    // }
    
    // cout<<"Enter the col values : "<<endl;
    // for(int i=0;i<2*e;i++){
    //     cin>>col[i];
    // }
    
    vector<edgeList> edges;
    cout<<"Enter the edges : "<<endl;
    for(int i=0;i<e;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;

    }
     auto start = chrono::high_resolution_clock::now();
    cout<<triangleCount(row_ptr,col,v,e);
    auto end = chrono::high_resolution_clock::now();

    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    
    
}