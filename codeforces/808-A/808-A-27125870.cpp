#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);

    long long year,copy;
    cin>>year;
    copy=year;

    int index=0,last_nzero=0,digit;
    while(copy) {
        
        if(copy%10) {
            last_nzero=index;
            digit=copy%10;
        }
        
        
        copy/=10;
        index++;
        
    }

    long long next=(digit+1)*pow(10,last_nzero);
    cout<<next-year;
    return 0;  
}