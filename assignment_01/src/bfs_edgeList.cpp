#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void bfsEdgeList(vector<int>& source,vector<int>& dest,int n,int v);
int main(){

    // No.of edges in graph

    int nodes;
    // cout<<"Enter the no.of Nodes : ";
    cin>>nodes;
    int n;
    // cout<<"Enter the no.of edges : ";
    cin>>n;
    cout<<endl;

    //Source Vertex
    vector<int> source(n,0);

    //Destination Vertex
    vector<int> dest(n,0);

    //weight of the Vertex
    vector<int> weight(n,0);


    //Assigning values
    for(int i=0;i<n;i++){
        cin>>source[i];
        cin>>dest[i];
        cin>>weight[i];
    }

    int v;
    // cout<<"Enter the source vertext : ";
    cin>>v;
    cout<<endl;

    //calling bfs
    auto start = chrono::high_resolution_clock::now();
    bfsEdgeList(source,dest,n,v);
    auto end = chrono::high_resolution_clock::now();

    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl; 
    return 0;
}