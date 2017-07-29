#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int price[110],favour[110];
int m,n;
int dp[110][15000]; //index,money left

int solve(int index, int money){
	if (money > m && m < 1800)
	{
		return -500;
	}

	if (money > m+ 200)
	{
		return -500;
	}

	if (index == n)
	{
		//
		if (money > m && money <=2000)
		{
			return -500;
		}
		return 0;
	}

	if (dp[index][money] !=-1)
	{
		return dp[index][money];
	}

	dp[index][money] = max(favour[index]+solve(index+1,money+price[index]),solve(index+1,money));
	return dp[index][money];
}

int main(){
	std::ios::sync_with_stdio(false);
	
	while(cin>>m>>n){
		
		F(i, 0, n){
			cin>>price[i]>>favour[i];
		}

		memset(dp, -1, sizeof(dp));

		//solve
		int ans = solve(0,0);
		cout<<ans<<"\n";
	}
	
	
	return 0;
}



/*
WRONG SOLUTION- THIS SOLUTIONS FAILS AT 
DEALING WITH THE EXTRA 200 SCHEME.


#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int price[110],favour[110];
int m,n;
int dp[110][10010]; //index,money left

int solve(int index, int money){
	if (index == n)
	{
		return 0;
	}

	if (money < price[index])
	{
		return dp[index][money] = solve(index+1,money);
	}

	if (dp[index][money] != -1)
	{
		return dp[index][money];
	}

	dp[index][money] = max(favour[index]+solve(index+1,money-price[index]),solve(index+1,money));
	return dp[index][money];
}

int main(){
	std::ios::sync_with_stdio(false);
	
	while(cin>>m>>n){
		
		if(m > 2000){
			m+=200;
		}

		F(i, 0, n){
			cin>>price[i]>>favour[i];
		}

		memset(dp, -1, sizeof(dp));

		//solve
		int ans = solve(0,m);
		cout<<ans<<"\n";
	}
	
	
	return 0;
}


*/