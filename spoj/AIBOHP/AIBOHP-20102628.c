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

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t;
	string s;
	cin>>t;

	while(t--){
		cin>>s;
		string rev = s;
		reverse(begin(rev),end(rev));

		int ans = s.length(),n=s.length();
		int dp[n+1][n+1];

		F(i, 0, s.length()){
			dp[i][0]=0;
			dp[0][i]=0;
		}

		F(i, 1, n+1){
			F(j, 1, n+1){
				if (s[i-1]==rev[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}else{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		ans-=dp[s.length()][s.length()];
		cout<<ans<<"\n";
	}

	return 0;
}