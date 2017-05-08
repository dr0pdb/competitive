#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){

    int nbooks,money;

    while(scanf("%d",&nbooks)==1){
        int prices[nbooks];
        for (size_t i = 0; i < nbooks; i++)
        {
            scanf("%d",&prices[i]);
        }
        scanf("%d",&money);
        cin.ignore();

        sort(prices,prices+nbooks);
        int i=0,j=nbooks-1;
        int bi,bj;
        while(i<=j){
            if(prices[i]+prices[j]==money){
                bi=i;
                bj=j;
                i++;
                j--;
            }
            else if(prices[i]+prices[j]<money){
                i++;
            }else{
                j--;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",prices[bi],prices[bj]);
        
    }
    
 return 0;  
}

