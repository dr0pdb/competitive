#include<bits/stdc++.h>
using namespace std;


int geti() {
  char c;int ret = 0;bool start = false;
  while(true) {
    c = getchar();
    if((c- '0' < 0 || c- '0' > 9) && !start) continue;
    if((c-'0' < 0 || c -'0' > 9) && start) break;
    if(start) ret *= 10;
    start = true;
    ret += c-'0';
  }
  return ret;
}

int main(){

 int n;
 long size=(1<<15);
 int weight[size];
 long pot[size];
 long maximum;
 while (scanf("%d",&n)==1)
 { 
   maximum=0;
   
   for(long i=0;i<size;i++){
       pot[i]=0;
   }  
     
   size=(1<<n);
   
     
   for (long i = 0; i < size; i++)
   {
     scanf("%d",&weight[i]);
   }

   for (long i = 0; i < size; i++)
   {
     for (int j = 0; j < n; j++)
     {
       pot[i]+=weight[i^(1<<j)];
     }
   }
    
   for (long i = 0; i < size; i++)
   {
    for (int j = 0; j < n; j++)
    {
      maximum=max(maximum,pot[i]+pot[i^(1<<j)]);
    } 
   }
   printf("%ld\n",maximum);
 }  
    return 0;    
}



