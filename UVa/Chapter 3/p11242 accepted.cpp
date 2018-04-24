#include<bits/stdc++.h> 

using namespace std;

int main(){

int fs,rs;
while (scanf("%d",&fs)==1 && fs)
{
    scanf("%d",&rs);
    int ft[fs];
    int rt[rs];

    for (size_t i = 0; i < fs; i++)
    {
        scanf("%d",&ft[i]);
    }for (size_t i = 0; i < rs; i++)
    {
        scanf("%d",&rt[i]);
        
    }

    float dratio[fs*rs];
    int count=0;
    for (size_t i = 0; i < fs; i++)
    {
        for (size_t j = 0; j < rs; j++)
        {
            dratio[count++]=(float)rt[j]/ft[i];
                   
         }
    }
    int size=fs*rs;
    sort(dratio,dratio+size);
    float maxm=0.0;
    for (size_t i = 0; i < size-1; i++)
    {
        float temp=(float)dratio[i+1]/dratio[i];
        if (temp>maxm)
        {
            maxm=temp;
        }
    }
    printf("%.2f\n",maxm);
}    
    
 return 0;  
}

