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
void(long a){
  long temp=0;

    for (int i = 0; i < 32; i++)
    {
      if (a & (1<<i))
      {
        temp|= (1<< (3-i/8)*8+(i%8));
      }
    }
    printf("%ld converts to %ld\n",a,temp);

}



int main(){
  //first number-input
 //  00000111    01011011      11001101      00010101
  //second number-output
  //00010101    11001101    01011011       00000111  
  
  long no;
  while (scanf("%ld",&no))
  {
    getAnswer(no);
  }

    return 0;    
}



