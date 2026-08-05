#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
void dfsEdgeList(vector<int>& source,vector<int>& dest,int n,int v);
int main(){

    int nodes;
    // cout<<"Enter the no.of Nodes : ";
    cin>>nodes;
    int n;
    // cout<<"Enter the no.of edges : ";
    cin>>n;
    cout<<endl;

    vector<int> source(n,0);
    vector<int> dest(n,0);
    vector<int> weight(n,0);

    for(int i=0;i<n;i++){
        cin>>source[i];
        cin>>dest[i];
        cin>>weight[i];
    }
    int v;
    // cout<<"Enter the source vertex :";
    cin>>v;

    auto start = chrono::high_resolution_clock::now();
    dfsEdgeList(source,dest,n,v);
    auto end = chrono::high_resolution_clock::now();

    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;

    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl; 
    return 0;
}