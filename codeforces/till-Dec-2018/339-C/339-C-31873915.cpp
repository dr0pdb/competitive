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
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

vi wts;
bool solved = false;
// int dp[1005][12][20];

void solve(int turnsLeft,int last,int diff,deque<int> ans,bool leftturn){

	if (solved)
	{
		return;
	}

	if (!turnsLeft)
	{
		solved = true;
		cout<<"YES\n";
		F(i, 0, ans.size()){
			cout<<ans[i]<<" ";
		}
		return;
	}

	if (diff>10)
	{
		return;
	}

	// if (dp[turnsLeft][last][diff] != -1)
	// {
	// 	return dp[turnsLeft][last][diff];
	// }

	F(i, 0, wts.size()){

		if (wts[i]==last)
		{
			continue;
		}

		if (leftturn)
		{
			if (diff+wts[i]<=0)
			{
				continue;
			}
			ans.push_back(wts[i]);
			solve(turnsLeft-1,wts[i],diff+wts[i],ans,false);
			ans.pop_back();		
		}else{
			if (diff-wts[i]>=0)
			{
				continue;
			}
			ans.push_back(wts[i]);
			solve(turnsLeft-1,wts[i],diff-wts[i],ans,true);
			ans.pop_back();
		}
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

 	string s;
 	cin>>s;
 	int m;
 	cin>>m;

 	F(i, 0, s.length()){
 		if (s[i]=='1')
 		{
 			wts.push_back(i+1);
 		}
 	}

 	F(i, 0, wts.size()){
 		deque<int> ans;
 		if (!solved)
 		{
 			ans.clear();
 			ans.push_back(wts[i]);
 			solve(m-1,i,wts[i],ans,false);
 		}
 	}

 	if (!solved)
 	{
 		cout<<"NO";
 	}

 	return 0;
}