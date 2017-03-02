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

  
  string s;
  int score;

  while (true)
  {
    getline(cin,s);
    score=0;

    if (s[0]=='G')
    {
      break;
    }
    int frames=1;
    int rolls=0;

    for (size_t i = 0; i < s.length();i+=2)
    {
        if (s[i]=='X')
        {
          if (frames<=10)
          {
            score+=10;
          }  
          
            if (frames<=10)
          {
              for (size_t j = 2; j <=4; j+=2)
            {
              if (s[i+j]=='X')
              {
                score+=10;
              }
              else if (s[i+j]=='/')
              {
                score+=(10-(s[i+j-2]-'0'));
              }

             else
              {
                score+=(s[i+j]-'0');
              }

            } 

          }  
            frames++;

        }

       else if (s[i]=='/')
        {
          rolls=0;
          
          if (frames<=10)
          {
            score+=(10-(s[i-2]-'0'));
          }  
          
          if (frames<=10)
          {
              if (s[i+2]=='X' )
            {
              score+=10;
            }
            else
            {
              score+=(s[i+2]-'0');
            }
          }
           frames++;          
        }

        else
        {
          rolls++;
          
          if (frames<=10)
          {
            score+=(s[i]-'0');           
          }  
        
            if (rolls==2)
            {
                frames++;
                rolls=0;  
            }
         
        }

    } 
      printf("%d\n",score);
    }
  
           return 0;    
}
