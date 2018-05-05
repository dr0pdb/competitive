#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int m;
   int n;
   cin>>m;
   cin>>n;
   int z=min(m,n);
   if(z%2==0){
    cout<<"Malvika";
   }
   else{
    cout<<"Akshat" ;
   }



    return 0;
}