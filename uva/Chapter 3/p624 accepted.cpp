#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int length,number;
vector<int> best_path;
int max_sum=0;
int tracks[100];

void ans(vector<int>v, int sum, int index){

    sum+=tracks[index];
    v.push_back(tracks[index]);

    if(sum>max_sum || (sum==max_sum && v.size()>best_path.size())) {
        max_sum=sum;
        best_path=v;
    }
    
    for(int i=index+1;i<number;i++){
        
        if(sum+tracks[i]<=length) {
            ans(v,sum,i);
        }
        
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    
    vector<int>v;    

    while(cin>>length>>number) {
        best_path.clear();
        max_sum=0;
        
        for(unsigned i = 0; i < number; ++i) {
            cin>>tracks[i];
        }
        for(unsigned i = 0; i < number; ++i) {
            v.clear();
            ans(v,0,i);
        }
        
        for(unsigned i = 0; i < best_path.size(); ++i) {
            cout<<best_path[i]<<" ";
        }
        cout<<"sum:"<<max_sum<<"\n";
    }
    

    return 0;  
}

