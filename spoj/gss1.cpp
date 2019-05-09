#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 1000000+10
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

const ll N = 50000+5;
ll n,q,arr[N];

struct node {
	ll best,prefixBest,suffixBest,sum;

	node(){
		best = suffixBest = prefixBest = sum = 0;
	}

	node(ll value){
		best = suffixBest = prefixBest = sum = value;	
	}

	//using the divide and conquer method of max subarray sum.
	void merge(node left, node right){
		sum = left.sum + right.sum;
		prefixBest = max(left.prefixBest,left.sum+right.prefixBest);
		suffixBest = max(right.suffixBest,right.sum+left.suffixBest);
		best = max(left.best,max(right.best,left.suffixBest+right.prefixBest));
	}
}st[4*N];

void build(ll p , ll l ,ll r){
	if (l == r)
	{
		st[p] = node(arr[l]);
		return;
	}

	build(left(p),l,(l+r)/2);
	build(right(p),(l+r)/2+1,r);
	st[p] = node();
	st[p].merge(st[left(p)],st[right(p)]);
}

node rsqm(ll p ,ll l, ll r, ll i,ll j){
	if (i > r || j < l) {
		node n(-INF);
		n.sum = 0;
		return n;	
	}  
	if (l >= i && r <= j) return st[p];

	node p1 = rsqm(left(p), l, (l+r)/2, i, j);
	node p2 = rsqm(right(p), (l+r)/2+1,r, i, j);
	node sum = node();
	sum.merge(p1, p2);
	return sum;
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	n = nextll();
	F(i, 0, n){
		arr[i]=nextll();
	}
	q = nextll();
	memset(st,0,sizeof(st));
	build(1,0,n-1);
	ll l,r;
	while(q--){
		l = nextll();
		r = nextll();
		l--;
		r--;
		printf("%lld\n",rsqm(1,0,n-1,l,r).best);
	}	


	return 0;
}
