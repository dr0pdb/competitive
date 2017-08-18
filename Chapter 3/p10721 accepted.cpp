#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int n,k,m;
ll dp[52][52];

ll solve(int x , int y){
	if (dp[x][y] !=-1LL)
	{
		return dp[x][y];
	}

	if (x==0 && y==0)
	{
		return 1LL;
	}
	if (x==0 || y==0)
	{
		return 0LL;
	}

	ll res=0LL;
	//any number can be between 1 and m so we try every number and try to recursively
	//find the remaining sum out of y-1 numbers.
	F(i, 1, m+1){
		if (x-i<0)
		{
			break;
		}
		res+=solve(x-i,y-1); 
	}
	return dp[x][y]=res;
}

int main(){
	std::ios::sync_with_stdio(false);

	//answer is the number of permutations of k numbers(<=m) such that their sum is n.
	while(cin>>n>>k>>m){
		mes(-1,dp);
		ll ans = solve(n,k);
		cout<<ans<<"\n";
	}

	return 0;
}

