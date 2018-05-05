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

ll editdist(string a, string b, int m, int n){
	if (m==0)
	{
		return n;
	}
	if (n==0)
	{
		return m;
	}

	ll dp[m+1][n+1];
	F(i, 0, m+1){
		F(j, 0, n+1){
			if (i==0)
			{
				dp[i][j]=j;
			}
			else if (j==0)
			{
				dp[i][j]=i;
			}

			else if (a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
			}
		}
	}
	return dp[m][n];
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin>>t;
	string a,b;

	while(t--){
		cin>>a>>b;
		cout<<editdist(a,b,a.length(),b.length())<<"\n";
	}
	
	return 0;
}