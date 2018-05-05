#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;







int main()
{

while(true){

int n;
cin>>n;

if(n==-1){
break;
}

int candies[n];
int sum=0;

for(int x=0;x<n;x++){

cin>>candies[x];
sum+=candies[x];
}

int average=sum/n;

if(average*n != sum){
cout<<-1<<endl;
}

else{

int answer=0;
for(int x=0;x<n;x++){

    if(average- candies[x]>0){
    answer+=average- candies[x];
    }

}
cout<<answer<<endl;
}


}





		return 0;
}






