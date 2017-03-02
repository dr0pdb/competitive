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

  vector<int> v;

  int temp, numzeroes = 0;
 
  while(true) {
    
    do {
       temp=geti();
      if(temp==0) {
          numzeroes++; 
          if(v.size()) break;
          if(numzeroes == 3) break;
        }
      
      else {
            numzeroes = 0;
            v.push_back(temp);
        }
    
    } while (true);
    
    int time = 0;
 
    if(numzeroes == 3)
     {
         break;
     }
 
    numzeroes = 0 ;
    sort(v.begin(),v.end());

    for (int i = v[0]; i <= 18000; i++)
    {
        bool allGreen=true;

        for (size_t j =0; j<v.size(); j++)
        {
            if (i%(2*v[j])>=v[j]-5)
            {
                allGreen=false;
                break;
            }
        }
        if (allGreen)
        {
            time=i;
            break;
        }

    }

    if (time)
    {
        int hours=0;
        int minutes=0;
        int seconds=0;

        hours=time/3600;
        time%=3600;

        minutes=time/60;
        time%=60;

        seconds=time;

        printf("%02d:%02d:%02d\n",hours,minutes,seconds);
    }
    else
    {
        printf("Signals fail to synchronise in 5 hours\n");
    }
    v.clear();

  }  
           return 0;    
}
