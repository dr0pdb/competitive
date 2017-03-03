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
  
  int temp;
  vector<int> v;

  while (scanf("%d",&temp)==1)
  {
    v.push_back(temp);
    sort(v.begin(),v.end());

    int answer=(v[v.size()/2]+v[(v.size()-1)/2])/2;
    printf("%d\n",answer);
  }
    return 0;    
}
