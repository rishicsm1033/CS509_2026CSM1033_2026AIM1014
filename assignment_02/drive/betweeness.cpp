#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "../src/edge_list.h"

using namespace std;



void betweenness(int v,int e,vector<edgeList>& edges){
    vector<double> cb(v,0.0);
    for(int s=0;s<v;s++){
        stack<int> st;
        vector<vector<int>> P(v);
        vector<long long> sigma(v,0);
        vector<int> d(v,-1);

        queue<int> que;

        sigma[s]=1;
        d[s] = 0;
        que.push(s);
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            st.push(u);

            for(auto edge : edges){
                int w = -1;
                if(edge.src == u){
                    w = edge.dest;
                }
                else if(edge.dest==u){
                    w = edge.src;
                }
                if(w!=-1){
                    if(d[w]<0){
                        d[w] = d[u]+1;
                        que.push(w);
                    }
                    if(d[w]==d[u]+1){
                        sigma[w]+=sigma[u];
                        P[w].push_back(u);
                    }
                }
            }
            
        }
        vector<double> delta(v,0.0);
        while(!st.empty()){
            int w = st.top();
            st.pop();
            for(int u:P[w]){
                delta[u] += (static_cast<double>(sigma[u])/sigma[w])*(1.0+delta[w]);
            }
            if(w!=s){
                cb[w]+=delta[w];
            }
        }
        cout<<"Between Score :"<<endl;
        for(int i=0;i<v;i++){
            cout<<"vertex : "<<i<<" centrality : "<<cb[i]<<endl;
        }

    }
}