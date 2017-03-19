#include<bits/stdc++.h>

using namespace std;

int main(){

    int coefficients[25]={0};
    long long d,k,ans;

    int t;
    scanf("%d",&t);
    int degree;

    while (t--)
    {
        ans=0;
        scanf("%d",&degree);
        for (size_t i = 0; i <= degree; i++)
        {
            scanf("%d",&coefficients[i]);
        }
        scanf("%lld",&d);
        scanf("%lld",&k);

        int index=ceil((double)k/(double)d);
        int temp = ceil((-1 + sqrt(1+(8*index)))/((double)2));

        for (size_t i = 0; i <= degree; i++)
        {
            ans+=coefficients[i]*pow(temp,i);
        
        }
        printf("%lld\n",ans);

    }
     
    
}

