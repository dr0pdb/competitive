#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin>>t;

	int r,c;
	while(t--){
		cin>>r>>c;

		int mat[r][c],dp[r][c];
		F(i, 0, r){
			F(j, 0, c){
				cin>>mat[i][j];
			}
		}
		memset(dp,-1,sizeof(dp));
		F(i, 0, c){
			dp[0][i]=mat[0][i];
		}
		int ans=-1;
		F(i, 1, r){
			F(j, 0, c){
				dp[i][j]=dp[i-1][j];
				if (j>0)
				{
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
				}
				if (j<c-1)
				{
					dp[i][j] = max(dp[i][j],dp[i-1][j+1]);	
				}
				dp[i][j]+=mat[i][j];

			}
		}

		F(j, 0, c){
			ans = max(ans,dp[r-1][j]);
		}
		cout<<ans<<"\n";
	}

	return 0;
}