#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string line;
   while (true)
   {
     getline(cin,line);
     if (line=="#")
     {
       break;
     }

     if (next_permutation(line.begin(),line.end()))
     {
       cout<<line<<"\n";
     }
     else
     {
       printf("No Successor\n");
     }
   }
    return 0;    
}

