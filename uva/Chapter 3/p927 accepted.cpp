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

        int temp=1;
        while ((d*(temp)*(temp+1))<2*k)
        {
            temp++;
        }

        
        for (size_t i = 0; i <= degree; i++)
        {
            long long temp2=1;
            for (size_t j = 0; j < i; j++)
            {
                temp2*=temp;
            }
            ans+=coefficients[i]*temp2;
        
        }
        printf("%lld\n",ans);

    }
     
    
}
