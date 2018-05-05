#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
    

    int n,k,nweeks;
    cin>>n>>k;
    nweeks=n-k+1;

    int sleep[n];
    
    for(unsigned i = 0; i < n; ++i) {
        cin>>sleep[i];
    }
    long long temp_sum=0,total_sum=0;
    
    for(unsigned i = 0; i < k; ++i) {
        temp_sum+=sleep[i];
    }
    total_sum=temp_sum;
    
    for(unsigned i = k; i < n; ++i) {
        temp_sum-=sleep[i-k];
        temp_sum+=sleep[i];
        total_sum+=temp_sum;
    }
    double ans =(double)total_sum/(double) nweeks;
    printf("%.8f",ans);
    return 0;  
}