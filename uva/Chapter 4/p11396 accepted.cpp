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

    int v;
    int x,y;
    while(cin>>v && v){
        vector<int> ver[v+1];
        bool marked[v+1]={false};
        bool color[v+1]={false};
        isBipartite=true;
        
        while(cin>>x>>y && x && y){
            ver[x].push_back(y);
            ver[y].push_back(x);
        }
        //dfs
        for(unsigned i = 1; i <= v; ++i) {
            
            if(!marked[i]) {
                DFS(i,ver,marked,color);
            }
            
            if(!isBipartite) {
                break;
            }
        }
        
        if(isBipartite) {
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        
    }
    

    return 0;  
}
