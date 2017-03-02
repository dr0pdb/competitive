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

  int a,b,c,p,q;
  while ( scanf("%d %d %d %d %d",&a,&b,&c,&p,&q)==5)
  {
   

    if (a==0)
    {
      break;
    }

    int inversions;
    bool isUsed[53]={false};
    isUsed[a]=isUsed[b]=isUsed[c]=isUsed[p]=isUsed[q]=true;
    bool exists=false;
    
    for (int i = 1; i <= 52; i++)
    { 
      inversions=0;
      if (isUsed[i])
      {
        continue;
      }

      if (a>p) inversions++;
      if(b>q) inversions++;
      if(c>i) inversions++;
      if(inversions>=2){
        continue;
      }  
      
      inversions=0;
      if (a>p) inversions++;
      if(b>i) inversions++;
      if(c>q) inversions++;
      if(inversions>=2){
        continue;
      }  
      
      inversions=0;
      if (a>q) inversions++;
      if(b>i) inversions++;
      if(c>p) inversions++;
      if(inversions>=2){
        continue;
      }  
      inversions=0;
      if (a>q) inversions++;
      if(b>p) inversions++;
      if(c>i) inversions++;
      if(inversions>=2){
        continue;
      }  
      inversions=0;
      if (a>i) inversions++;
      if(b>p) inversions++;
      if(c>q) inversions++;
      if(inversions>=2){
        continue;
      }  
      inversions=0;
      if (a>i) inversions++;
      if(b>q) inversions++;
      if(c>p) inversions++;
      if(inversions>=2){
        continue;
      }  

      exists=true;
      printf("%d\n",i);
      break;
    }
    if (!exists)
    {
      printf("-1\n");    
    }
    

  }
  return 0;    
}
