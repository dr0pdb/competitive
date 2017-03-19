#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    scanf("%d",&t);
    string names[1000001];
    int min[1000001],max[1000001];
    int noc,noq,temp;
    int count=0;

    while (t--)
    {
        scanf("%d",&noc);
        for (size_t i = 0; i < noc; i++)
        {
            cin>>names[i];
            scanf("%d %d",&min[i],&max[i]);
        }

        scanf("%d",&noq);
        for (size_t i = 0; i < noq; i++)
        {
            scanf("%d",&temp);
            count=0;
            string s;
            for (size_t j = 0;j < noc; j++)
            {
                if (temp>=min[j] && temp<=max[j])
                {
                    count++;
                    s=names[j];
                }
            }
            if (count==1)
            {
               cout<<s<<endl;
            }else{
                printf("UNDETERMINED\n");
            }
        }
       if(t){
           printf("\n");
       } 
    }
    
}

