#include<bits/stdc++.h> 

using namespace std;

int main(){

   int t;
   scanf("%d",&t);

   int length,m,temp;
   string side;
   int counter,cside;
   int currLen;

   while (t--)
   {
       queue<int> q[2];
       cside=0;
       scanf("%d %d",&length,&m);
       length*=100;
       while(m--){
           cin>>temp>>side;
           
           if (side=="left")
           {
               q[0].push(temp);
           }else
           {
               q[1].push(temp);
           }
       }

       counter=0;
       while (! (q[0].empty() && q[1].empty()))

       {
            currLen=0;
            while (! q[cside].empty() && currLen + q[cside].front() <= length)

            {
                currLen+=q[cside].front();
                q[cside].pop();
            }
            counter++;
            cside ^=1;
       }
       printf("%d\n",counter);
   }
    return 0;
}

