#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int left(int p ){return p<<1;}
int right(int p ){return (p<<1)+1;}
/*----------------------------------------------------------------------*/

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	ll budget,n;
	while(cin>>budget>>n && budget+n ){

		vector<pair<ll, ll> >party;
		ll cost,fun;
		F(i, 0, n){
			cin>>cost>>fun;
			party.push_back(make_pair(cost, fun));
		}

		ll dp[n+1][budget+1];
		memset(dp,0,sizeof(dp));
		
		F(i, 0, n+1){
			F(j, 0, budget+1){
				if (j==0 || i==0)
				{
					dp[i][j]=0;
				}else if (party[i-1].first<=j)
				{
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-party[i-1].first]+party[i-1].second);
				}else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		fun=dp[n][budget],cost=budget;
		int j=n;
		RF(i, budget-1, 0){
			if (dp[j][i]==fun)
			{
				cost--;
			}else{
				break;
			}
		}
		cout<<cost<<" "<<fun<<"\n";
	}
	



	return 0;
}