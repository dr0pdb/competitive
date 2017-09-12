#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define mod 1000007
int t,n;
char matrix[105][105];
int dp[105][105];

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	cin>>t;

	F(tn, 1, t+1){
		cin>>n;
		F(i, 0, n){
			F(j, 0, n){
				cin>>matrix[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
	
		RF(i, n-1, 0){
			F(j, 0, n){
				if (matrix[i][j] == 'W')
				{
					dp[i][j]=1;
					continue;
				}else if (matrix[i][j] == 'B')
				{
					continue;
				}

				if (i+1<n && j+1<n && matrix[i+1][j+1]!='B')
				{
					dp[i][j]+=dp[i+1][j+1];
				}

				if (i+1<n && j-1>=0 && matrix[i+1][j-1] != 'B')
				{
					dp[i][j]+=dp[i+1][j-1];
				}

				if (i+1<n && j+1<n && matrix[i+1][j+1]=='B')
				{
					if (i+2<n && j+2<n && matrix[i+2][j+2]!='B')
					{
						dp[i][j]+=dp[i+2][j+2];
					}
				}
				if (i+1<n && j-1>=0 && matrix[i+1][j-1]=='B')
				{
					if (i+2<n && j-2>=0 && matrix[i+2][j-2]!='B')
					{
						dp[i][j]+=dp[i+2][j-2];
					}
				}
				dp[i][j] %= mod;
			}
		}
		
		ll ans=0;
		F(i, 0, n){
			if (matrix[0][i] !='B')
			{
				ans+=dp[0][i];
				ans%=mod;
			}
		}


		cout<<"Case "<<tn<<": "<<ans<<"\n";
	}

	return 0;
}