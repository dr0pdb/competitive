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

  string line;
  list<char> l;
  list<char>::iterator itr;

  while (getline(cin,line))
  {
    l.clear();
    itr=l.begin();
    for (size_t i = 0; i < line.length(); i++)
    {
      if (line[i]=='[')
      {
        itr=l.begin();
      }
      else if (line[i]==']')
      {
        itr=l.end();
      }
      else
      {
          l.insert(itr,line[i]);
      }
    }

    for(char x : l)
    {
      printf("%c",x);
    }
    printf("\n");
  }
    return 0;    
}



