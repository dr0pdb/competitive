#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int n;
int arr[105],dp[105][105],sum[105][105];

void reset(){
	F(i, 0, n){
		F(j, 0, n){
			dp[i][i]=0;
		}
	}
}

int solve(int a, int b){
	if (a==b)
	{
		return 0;
	}
	if (b==a+1)
	{
		return arr[a]*arr[b];
	}

	if (dp[a][b] != -1)
	{
		return dp[a][b];
	}
	int temp;
	F(i, a, b){
		temp = sum[a][i] * sum[i+1][b] + (solve(a,i) + solve(i+1,b));
		if (temp < dp[a][b] || dp[a][b] == -1)
		{
			dp[a][b]= temp;
		}
	}
	return dp[a][b];
}


int main(){
	//std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	while(cin>>n){
		F(i, 0, n){
			cin>>arr[i];
			sum[i][i]=arr[i];
		}
		
		F(i, 0, n){
			F(j, i+1, n){
				sum[i][j] = sum[i][j-1] + arr[j];
				if(sum[i][j] >= 100) sum[i][j] -= 100;
			}
		}
        memset(dp,-1,sizeof(dp));
		reset();
		cout<<solve(0,n-1)<<"\n";


	}

	return 0;
}