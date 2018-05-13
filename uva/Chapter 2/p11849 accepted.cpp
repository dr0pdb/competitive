#include<bits/stdc++.h>

using namespace std;

int main(){

   int n,m;
   set<long long> s;
   long long temp;
   long long counter;
   long long size_temp;

   while (scanf("%d %d",&n,&m)==2 && n && m)
   {
       s.clear();
       counter=0;

       while (n--)
       {
           scanf("%lld",&temp);
           size_temp=s.size();
           s.insert(temp);
           if (s.size()==size_temp)
           {
               counter++;
           }
       }
       while (m--)
       {
           scanf("%lld",&temp);
           size_temp=s.size();
           s.insert(temp);
           if (s.size()==size_temp)
           {
               counter++;
           }
       }

       printf("%lld\n",counter);
   }

    return 0;    
}



