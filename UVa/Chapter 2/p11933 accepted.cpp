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

  unsigned long number;
  unsigned long a,b;
  int count;

  while (scanf("%lud",&number)==1)
  {
    if (!number)
    {
      break;
    }
    a=0,b=0,count=0;
    for (int i = 0; i < 32; i++)
    {
      if (number&(1<<i))
      {
        if (!(count%2))
        {
          a^=(1<<i);
        }
        else
        {
          b^=(1<<i);
        }
        count++; 
      }
       
    }

    printf("%lu %lu\n",a,b);
  }

    return 0;    
}



