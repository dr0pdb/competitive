#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int numbers[210];
int dp[210][15][21]; //index,count,sum%d
int n,q,d,m,tn=1,ans;

int solve(int index,int counter, int sum){
	
	
	if (counter==m)
	{
		if (sum !=0)
		{
			return 0;
		}
		return 1;
	}

	if (index == n)
	{
		return 0;
	}

	if (dp[index][counter][sum] != -1)
	{
		return dp[index][counter][sum];
	}
   
	dp[index][counter][sum] = solve(index+1,counter,(sum%d + d)%d) + solve(index+1,counter+1,(sum%d+numbers[index]%d+ d)%d);
	return dp[index][counter][sum];
}

int main(){
	std::ios::sync_with_stdio(false);
	
	
	while(cin>>n>>q && n && q){
		F(i, 0, n){
			cin>>numbers[i];
		}
		cout<<"SET "<<tn++<<":\n";
		F(i, 0, q){
			cin>>d>>m;

			//fill_n(dp,sizeof(dp),-1);
			memset(dp, -1, sizeof(dp));
			
			//solve
			ans = solve(0,0,0);

			cout<<"QUERY "<<i+1<<": "<<ans<<"\n";

		}
	}
	return 0;
}

