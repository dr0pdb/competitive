#include<bits/stdc++.h> 

using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    int n;
    int arr[1050];
    long long ans;
    int sum;

    while (t--)
    {
        ans=0;
        scanf("%d",&n);
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
            sum=0;
            for (size_t j = 0; j < i; j++)
            {
                if (arr[j]<=arr[i])
                {
                    sum++;
                }
            }
            ans+=sum;
        }
        printf("%d\n",ans);
    }
 return 0;  
}

