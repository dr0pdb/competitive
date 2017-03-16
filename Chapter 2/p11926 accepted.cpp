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
bitset<1000001> timing;

bool hasConflict(int single, int repeat, int start[], int end[], int rinterval[]){

 
    for (int i = 0; i < single; ++i)
    {
        int s = start[i], e = end[i];
        
        for (int t = s + 1; t <= e; ++t)
        {
            if (timing.test(t))
                return true;
            else
                timing.set(t);
        }
    }
    
    for (int i = single; i < single+repeat; ++i)
    {
        int s = start[i], e = end[i], interval = rinterval[i-single];     
        while (s < 1000000)
        {
            for (int t = s + 1; t <= e; ++t)
            {
                if (timing.test(t))
                    return true;
                else
                    timing.set(t);
            }          
            s += interval;
            e = min(e + interval, 1000000);
        }
    }
    return false;}
int main(){


  int single, repeat;
  
  while ((scanf("%d %d",&single,&repeat)==2))
  {
      if (!single && !repeat)
      {
        break;
      }
     timing.reset();
     int start[single+repeat],end[single+repeat],rinterval[repeat];

     for (int i = 0; i < single; i++)
     {
       scanf("%d %d",&start[i],&end[i]);
       
     }    
     for (int i = 0; i < repeat; i++)
     {
       scanf("%d %d %d",&start[i+single],&end[i+single],&rinterval[i]);
     }

     bool answer= hasConflict(single,repeat,start,end,rinterval);
     if (answer)
     {
       printf("CONFLICT\n");
     }
     else
     {
       printf("NO CONFLICT\n");
     }

  }  
    return 0;    
}



