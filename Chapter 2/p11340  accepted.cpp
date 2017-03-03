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
  
    int testcase=geti();
    int no_chars;
    map<char,int> values;
    double answer;  

    while (testcase--)
    { 
      values.clear();  
      answer=0.00;
      no_chars=geti();
      char temp;
      int temp_no;
      while (no_chars--)
      {
        temp=getchar();
        temp_no=geti();

        values[temp]=temp_no;
      }
      temp_no=geti();
      string line;
      while (temp_no--)
      {
        getline(cin,line);
          for (size_t i = 0; i < line.length(); i++)
        {
            map<char,int>::iterator itr=values.find(line[i]);
            if (itr != values.end())
            {
                answer+=values[line[i]];
            }
            
        }
      }
      answer/=100;
      printf("%.2f$\n",answer);  
    }

    return 0;    
}
