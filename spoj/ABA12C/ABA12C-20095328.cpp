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

vii packets;
int t,n,k;

int solve(int totalwt){
	
	int dp[totalwt+1];
	dp[0]=0;
	for (int i = 1; i <= totalwt; ++i)
	{
		int q = INF;
		for (int j = 0; j < packets.size(); ++j)
		{
			if (packets[j].first<= i && dp[ i- packets[j].first]!=INF)
			{
				q = min(q,dp[ i- packets[j].first] + packets[j].second);
			}
		}
		dp[i]=q;
	}
	return dp[totalwt];
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--){
		packets.clear();
		cin>>n>>k;
		int x;
		F(i, 0, k){
			cin>>x;
			if (x!=-1)
			{
				packets.push_back(ii(i+1,x));
			}
		}
		int ans = solve(k);
		if (ans==INF)
		{
			cout<<"-1\n";
		}else{
	        cout<<ans<<"\n";
		}	

	}
	return 0;
}