#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isConnected(vector<int>& col,int start,int end,int v){
    sort(col.begin()+start,col.begin()+end);
    return binary_search(col.begin()+start,col.begin()+end,v);

}
int triangleCount(vector<int>& row_ptr, vector<int>& col,int v, int e){
    int count = 0;
    for(int k=0;k<v;k++){
        
        for(int i=row_ptr[k];i<row_ptr[k+1];i++){
            for(int j=i+1;j<row_ptr[k+1];j++){
                
                int v1 = col[i];
                int v2 = col[j];
                if(isConnected(col,row_ptr[v1],row_ptr[v1+1],v2)){
                    count++;
                }
            }

        }
    }
    return count/3;
}