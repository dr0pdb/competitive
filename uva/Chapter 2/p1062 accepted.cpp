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
vector<char> v;


void addIt(char x){
  bool t=false;
  for (size_t i = 0; i < v.size(); i++)
  {
    if (x<=v[i])
    {
      v[i]=x;
      t=true;
      break;
    }
    
  }
  if (!t)
  {
    v.push_back(x);
    
  }

}

int main(){

  string line;
  int counter=1;
  
  while (true)
  {
    v.clear();    
    getline(cin,line);
    if (line =="end")
    {
      break;
    }

    
    printf("Case %d: ",counter++);
    for (size_t i = 0; i < line.length(); i++)
    {
        addIt(line[i]);  
    }
    printf("%d\n",v.size());
  }
  
    return 0;    
}



