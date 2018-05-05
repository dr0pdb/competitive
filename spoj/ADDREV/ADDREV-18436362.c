#include <iostream>
#include<algorithm>
using namespace std;
int reversethedigits(int x);






int main()
{

int t;
cin>>t;

while(t-- !=0){

int a;
int b;
cin>>a>>b;

int arev=reversethedigits(a);
int brev=reversethedigits(b);
int sum=arev+brev;
int answer=reversethedigits(sum);

cout<< answer<<endl;




		}
		return 0;
}

int reversethedigits(int x){

int num=0;

while(x>0){
num=num*10+(x%10);
x=x/10;
}

return num;


}







