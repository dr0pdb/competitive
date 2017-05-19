#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
bool isBipartite;

void DFS(int index,vector<int>ver[], bool marked[],bool color[]){
    
    
    if(!isBipartite) {
        return;
    }
    
    
    marked[index]=true;
    for(auto itr =ver[index].begin();itr != ver[index].end();++itr) {
        
        if(!marked[*itr]) {
            color[*itr]= !color[index];
            DFS(*itr,ver,marked,color);
        }else if(color[index]==color[*itr]){
            isBipartite=false;
            return;
        }
        
    }

}

int main(){
    std::ios::sync_with_stdio(false);

    int n,l;
    int n1,n2;
    while(cin>>n && n) {
        cin>>l;
        vector<int> ver[n];
        
        while(l--) {
            cin>>n1>>n2;
            ver[n1].push_back(n2);
            ver[n2].push_back(n1);
        }
        isBipartite=true;
        bool marked[n]={false};
        bool color[n]={false};      //false for color 1 and true for color 2
        //dfs
        for(unsigned i = 0; i < n; ++i) {
            
            if(!marked[i]) {
                DFS(i,ver,marked,color);
            }
            
            if(!isBipartite) {
                break;
            }
            
            
        }
        
        if(isBipartite) {
            cout<<"BICOLORABLE."<<"\n";
        }else{
            cout<<"NOT BICOLORABLE."<<"\n";
        }
        
    }
    
    
    return 0;  
}
