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

int value(string s){
    switch(s[0]){

      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
                return (s[0]-'0');
                break;
      default: return 10;
                break;
    }


}


int main(){
  
  int tc=geti();
  int y,x;

  string temp;
  vector<string> v;

  for (int i = 0; i < tc; i++)
  {
      v.clear();
      y=0;

      for (size_t j = 0; j < 52; j++)
      {
        cin>>temp;
        v.push_back(temp);
      }

      reverse(v.begin(),v.end());
      for (size_t j = 0; j < 3; j++)
      {
          x=value(v[25]);
          y+=x;
          v.erase(v.begin()+25,v.begin()+25+(10-x)+1); 
      }
      
      reverse(v.begin(),v.end());
      cout<<"Case "<<(i+1)<<": "<<v[y-1]<<"\n";
  }

  
  return 0;    
}
