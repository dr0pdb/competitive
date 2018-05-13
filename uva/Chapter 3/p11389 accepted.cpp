#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
    int n,d,r;
    
    while(scanf("%d %d %d",&n,&d,&r)==3 && (n || d || r)) {
        vector<int> mr,ev;
        
        for(unsigned i = 0; i < n; ++i) {
           int temp;
           scanf("%d",&temp);
           mr.push_back(temp);
        }
         for(unsigned i = 0; i < n; ++i) {
           int temp;
           scanf("%d",&temp);
           ev.push_back(temp);
        }

        sort(mr.begin(),mr.end());
        sort(ev.begin(),ev.end());

        int answer=0;
        
        for(unsigned i = 0; i < n; ++i) {
            int diff=mr[i]+ev[n-i-1]-d;
            if(diff>0) {
                answer+=(diff)*r;
            }
        }
        printf("%d\n",answer);    
    }
    return 0;  
}

