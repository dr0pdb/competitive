#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int findanswer(int x);






int main()
{

int n;
cin>>n;

int answer=0;

for(int x=1;x<=n;x++){

answer+=findanswer(x);
}
cout<<answer<<endl;



		return 0;
}

int findanswer(int p){

int nofactors=0;
for(int x=1;x<=(int)sqrt(p);x++){

if(p%x==0){
nofactors++;
}


}

return nofactors;
}
