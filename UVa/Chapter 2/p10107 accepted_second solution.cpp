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
  
  int l = 0, k;
    unsigned int n, v[10000];
    while(cin >> n) {
        k = lower_bound(v,v+l,n) - v;
        l++;
        for(int i = l-1; i >= k+1; i--) {
            v[i] = v[i-1];
        }
        v[k] = n;
        cout << (v[l/2] + v[(l-1)/2])/2 << endl;
    }
    return 0;    
}
