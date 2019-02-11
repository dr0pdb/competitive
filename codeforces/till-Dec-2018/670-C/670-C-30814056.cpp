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

	ll n;
	cin>>n;

	//lang index to its number of occurence.
	std::map<ll, ll> present;
	ll a;

	F(i, 0, n){
		cin>>a;
		if (present.find(a) != present.end())
		{
			present[a]++;
		}else{
			present[a]=1;
		}
	}

	ll m;
	cin>>m;
	std::vector<pair<ll,ll> > movie(m);
	ll b;
	
	F(i, 0, m){
		cin>>b;
		movie[i] = make_pair(b,0);
	}
	F(i, 0, m){
		cin>>b;
		ll curr = movie[i].first;
		movie[i] = make_pair(curr,b);
	}
	pair<ll, ll>res,curr;
	res = make_pair(0,0);
	ll ans=0;
	F(i, 0, m){
		curr = movie[i];
		if (res.first<present[curr.first] || (res.first==present[curr.first] && res.second<present[curr.second]))
		{
			res = make_pair(present[curr.first], present[curr.second]);
			ans = i;
		}
	}
	cout<<ans+1;
	return 0;
}