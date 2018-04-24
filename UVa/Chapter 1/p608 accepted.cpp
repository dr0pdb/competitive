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

string words[3][3];

bool check(char a, bool heavy){

  int left,right;

  for (size_t i = 0; i < 3; i++)
  {
    left=0;
    right=0;

    for (size_t j = 0; j < words[i][0].length(); j++)
    {
        if (words[i][0][j]==a)
        {
          if (heavy)
          {
            left+=50;
          }
          else
          {
            left-=50;
          }
        }
        else{
          left+=1;
        }
    }

    for (size_t j = 0; j < words[i][1].length(); j++)
    {
      if (words[i][1][j]==a)
      {
        if (heavy)
        {
          right+=50;
        }
        else
        {
          right-=50;
        }
      }
      else
      {
        right+=1;
      }
    }
    
    if (words[i][2]=="even")
    {
      if (left != right)
      {
            return false;
      }
    }
    
    else if (words[i][2]=="up")
    {
      if (left<=right)
      {
            return false;
      }
    }

    else if(words[i][2]=="down"){
      if (right<=left)
      {
            return false;  
      }
      
    }
  }
  
  return true;
}

int main(){
  
  int t=geti();
  

  while (t--)
  {
    for (size_t i = 0; i < 3; i++)
    {
      for (size_t j = 0; j < 3; j++)
      {
        cin>>words[i][j];
      }
    }

    for (char c = 'A';c<='L'; c++)
    {
      if (check(c,true))
      {
        printf("%c is the counterfeit coin and it is heavy.\n",c);
      }
      else if(check(c,false))
      {
        printf("%c is the counterfeit coin and it is light.\n",c);
      }
    }


  }
  return 0;    
}
