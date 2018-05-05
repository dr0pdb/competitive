#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;







int main()
{

int t;
cin>>t;

while(t-- !=0){

int n;
cin>>n;

int incoming[n];
int outgoing[n];

for(int x=0;x<n;x++){
cin>>incoming[x];
cin>>outgoing[x];
}

sort(incoming,incoming+n);
sort(outgoing,outgoing+n);

int counter=0;
int max=0;


for(int c1=0,c2=0;c1<n && c2<n;){

if(incoming[c1]<outgoing[c2]){
counter++;
if(counter>max){
max=counter;
}
c1++;
}

else{
counter--;
c2++;
}



}
cout<<max<<endl;

}


		return 0;
}






