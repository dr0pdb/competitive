#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
vector<int> v;
void DFS(int index,vector<int>ver[], bool visited[]){
    visited[index]=true;
    for(auto itr =ver[index].begin();itr != ver[index].end();++itr) {
        
        if(!visited[*itr]) {
            DFS(*itr,ver,visited);
        }
        
    }
    v.push_back(index);
}

int main(){
    std::ios::sync_with_stdio(false);

    int n,m,from,to;
    
    while(cin>>n>>m && (n || m)) {
        vector<int> ver[n+1];
        
        while(m--) {
            cin>>from>>to;
            ver[from].push_back(to);
        }
        
        v.clear();
        bool visited[n+1]={false};

        //dfs
        for(int i=1;i<=n;i++){
            
            if(!visited[i]) {
                DFS(i,ver,visited);
            }
       }
        
       for(auto itr = v.rbegin();itr !=v.rend();++itr){
           cout<<*itr;
           
           if(n >1) {
               cout<<" ";
           }
           n--;
       } 
       
       cout<<"\n";
    }
    return 0;  
}
