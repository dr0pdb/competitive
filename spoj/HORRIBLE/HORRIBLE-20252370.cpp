#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iomanip>
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

const int N = 1e6+10;
ll n;
ll arr[N],lazy[4*N];

struct node{
	ll value;

	node(){
		value = 0;
	}
	node(int v){
		value = v;
	}
	void merge(node left, node right){
		value = left.value + right.value;	
	}
} st[4*N];

node query(ll p , ll l, ll r,ll x,ll y){

	if (lazy[p])
	{
		st[p].value+=(r-l+1)*lazy[p];
		if (l!=r)
		{
			lazy[left(p)]+=lazy[p];
			lazy[right(p)]+=lazy[p];
		}
		lazy[p]=0;
	}

	if (x>r || y<l)
	{
		return node(0);
	}
	if (l>=x && r<=y)
	{
		return st[p];
	}

	ll mid = (l+r)/2;

	node p1 = query(left(p), l, mid, x, y);
	node p2 = query(right(p),mid+1,r,x,y);
	node n = node(0);
	n.merge(p1, p2);
	return n;
}

void rangeUpdate(ll p, ll l , ll r,ll x, ll y,ll value){
	if (lazy[p])
	{
		st[p].value+=(r-l+1)*lazy[p];
		if (l!=r)
		{
			lazy[left(p)]+=lazy[p];
			lazy[right(p)]+=lazy[p];
		}
		lazy[p]=0;
	}

	if (x>r || y<l)
	{
		return;
	}
	if (l>=x && r<=y)
	{
		st[p].value+=(r-l+1)*value;
		if (l!=r)
		{
			lazy[left(p)]+=value;
			lazy[right(p)]+=value;
		}
		lazy[p]=0;
		return;
	}

	ll mid = (l+r)/2;

	rangeUpdate(left(p), l, mid, x, y,value);
	rangeUpdate(right(p),mid+1,r,x,y,value);
	node n = node(0);
	n.merge(st[left(p)],st[right(p)]);
	st[p]=n;
}	

// void printTree(){
// 	printf("Printing the treeeeee\n");
// 	F(i, 1, 4*n){
// 		printf("  %lld  ", st[i].value);
// 	}
// 	printf("\n");
// }

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t,q;
	t = nextint();

	while(t--){
		n = nextll();
		q = nextint();

		F(i, 0, 4*N){
			st[i].value = 0;
			lazy[i]=0;
		}
		int type;
		F(i, 0, q){
			type = nextint();

			if (!type)
			{
				ll l = nextll(),r = nextll();
				ll value = nextll();
				rangeUpdate(1, 0, n-1, l-1, r-1, value);
				// printTree();
			}else{
				ll l=nextll(),r=nextll();			
				printf("%lld\n",query(1,0,n-1,l-1,r-1).value);
			}
		}
		cin.ignore();
	}


	return 0;
}