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

    long long size,element;
    
    while (true)
    {
      scanf("%lld %lld",&size,&element);
      if (!size && !element)
      {
        break;
      }

      long long x=(size+1)/2;
      long long y=(size+1)/2;
      long long value=sqrt(element);
      if (value*value==element && (value%2))
      {
        
      }
      else if (value*value==element && (!value%2))
      {
        --value;
      }else 
      {
        if (value%2)
        {
          
        }else
        {
          value--;
        }
      }
      x+=(value-1)/2;
      y+=(value-1)/2;

      element-=value*value;

      if (element)
      {
          value++;
              if (element <= value) {
            x -= element - 1; y++;
          }
          else if (element <= value * 2) {
            x -= value - 1; y -= element - value - 1;
          }
          else if (element <= value * 3) {
            x -= value * 3 - element - 1; y -= value - 1;
          }
          else {
            x++; y -= value * 4 - element - 1;
          }

      }

       printf("Line = %d, column = %d.\n",y,x);




    }
    return 0;    
}
