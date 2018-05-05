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

int sum[2][503][503];
int blogg[503][503],yeyenum[503][503];
int dp[503][503];
int n,m;

void solve(){
	F(i, 0, n){
		F(j, 0, m){
			int temp1 = sum[0][i][j];
			int temp2 = sum[1][i][j];
			if (j>0)
			{
				temp1+=dp[i][j-1];
			}
			if (i>0)
			{
				temp2+=dp[i-1][j];
			}
			dp[i][j] = max(temp1, temp2);
		}
	}
	cout<<dp[n-1][m-1]<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	while(cin>>n>>m && n && m){
		memset(dp,0,sizeof(dp));
		F(i, 0, n){
			F(j, 0, m){
				cin>>yeyenum[i][j];
				sum[1][i][j]=yeyenum[i][j];
				if (j>0)
				{
					sum[1][i][j]+=sum[1][i][j-1];
				}
			}
		}

		F(i, 0, n){
			F(j, 0, m){
				cin>>blogg[i][j];
				sum[0][i][j]=blogg[i][j];
				if (i>0)
				{
					sum[0][i][j]+=sum[0][i-1][j];
				}
			}
		}

		solve();

	}

	

	return 0;
}