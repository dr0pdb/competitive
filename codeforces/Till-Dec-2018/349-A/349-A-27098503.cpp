#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    
   int n;
   cin>>n;

   int temp;
   int tf=0,f=0,h=0;
   bool isPossible=true;
   
   for(unsigned i = 0; i < n; ++i) {
       cin>>temp;

       
       if(temp==25) {
           tf++;
       }else if(temp==50){
           f++;
           
           if(!tf) {
               isPossible=false;
           }else{
               tf--;
           }
        }else{
            h++;
            
            if(f>=1 && tf>=1 ) {
                f--;
                tf--;
            }else if(tf>=3){
                tf-=3;
            }else{
                isPossible=false;
            }
            
        }
       
   }
   
   if(isPossible) {
       cout<<"YES";
   }else{
       cout<<"NO";
   }
    

    return 0;  
}