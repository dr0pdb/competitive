#include<bits/stdc++.h>

using namespace std;

int main(){

   int t,temp;
   long long int cost; 
   
   while (scanf("%d",&t)==1 && t)
      {
      priority_queue<int,vector<int>,greater<int> > pq;      
       cost=0;
       for (size_t i = 0; i < t; i++)
       {
           scanf("%d",&temp);
           pq.push(temp);
       }
       while (pq.size()>1)
       {
           temp=pq.top();
           pq.pop();
           temp+=pq.top();
           pq.pop();
           cost+=temp;
           pq.push(temp);
       }
       printf("%lld\n",cost);
   }

    return 0;    
}

