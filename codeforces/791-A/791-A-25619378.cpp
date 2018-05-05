#include<bits/stdc++.h>

using namespace std;

int main(){

    int w1,w2;
    scanf("%d %d",&w1,&w2);
    int t=0;
    while(w1<=w2){
        t++;
        w1*=3;
        w2*=2;
    }
    printf("%d",t);

}