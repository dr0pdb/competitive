#include<bits/stdc++.h> 

using namespace std;

int main(){

    int n,m,query,caseno=1;
    int arr[1050];

    while (scanf("%d",&n)==1 && n)
    {   
        printf("Case %d:\n",caseno++);
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);   
        }

        scanf("%d",&m);
        for (size_t i = 0; i < m; i++)
        {
            scanf("%d",&query);
            int sum;
            int closest;
            
            for (size_t j = 0; j <n-1 ; j++)
            {
                for (size_t k = j+1; k < n; k++)
                {
                    sum=arr[j]+arr[k];
                    if (abs(sum-query)< abs(closest-query))
                    {
                        closest=sum;
                        
                    }
                }
            }
            printf("Closest sum to %d is %d.\n",query,closest);
        }
    }

 return 0;  
}

