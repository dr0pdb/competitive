#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int coins[5]={1,5,10,25,50};
long long memo[5][30010];

long long answer(int type , int value){
	if (type> 4) return 0;
	if (value == 0) return 1;
	if (value <0) return 0;

	if (memo[type][value] != -1) return memo[type][value];

	return memo[type][value] = answer(type+1,value)+ answer(type,value-coins[type]);
}

int main(){
	std::ios::sync_with_stdio(false);
	F(i, 0, 5){
		F(j, 0, 30010){
			memo[i][j]=-1;
		}
	}
	int targetvalue;
	while(cin>>targetvalue){
		long long ans = answer(0,targetvalue);
		if (ans == 1)
		{
			cout<<"There is only 1 way to produce "<<targetvalue<<" cents change."<<"\n";
		}else{
			cout<<"There are "<<ans<<" ways to produce "<<targetvalue<<" cents change."<<"\n";
		}
	}

	
	return 0;
}