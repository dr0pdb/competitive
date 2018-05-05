#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int findanswer(int x);






int main()
{

int t;
cin>>t;

while(t-- !=0){

int n;
int k;
cin>>n>>k;

int numbers[n];
for(int x=0;x<n;x++){
cin>>numbers[x];
}

sort(numbers,numbers+n);

int minimum=1000000001 ;
for(int x=0;x<=n-k;x++){

if(numbers[x+k-1]-numbers[x]<minimum){
minimum=numbers[x+k-1]-numbers[x];
}

}

cout<<minimum<<endl;
}



		return 0;
}

