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
  
  int t;
  int count=1;
  while (scanf("%d",&t))
  {
    if (t==0)
    {
      break;
    }
    
    long long numbers[t+1];
    numbers[t]=0;

    for (size_t i = 0; i < t; i++)
    {
      scanf("%lld",&numbers[i]);
    }

    
    printf("Case %d:\n",count++);
    for (size_t i = 0; i < t; i++)
    {
      if (numbers[i]+1 != numbers[i+1])
      {
        printf("0%lld\n",numbers[i]);
      }

      else
      {
        printf("0%lld-",numbers[i]);
        size_t j=i+1;
        for ( ; (numbers[j]+1)==numbers[j+1]; ++j)
        {
          
        }
        long long first=numbers[i],second=numbers[j];

        long long multiplier=10;

        while ((first-(first%multiplier))!=(second-(second%multiplier)))
        {
          multiplier*=10;
        }
        printf("%lld\n",second%multiplier);
        i=j;
      }
    }
    printf("\n");
  }
  return 0;    
}
