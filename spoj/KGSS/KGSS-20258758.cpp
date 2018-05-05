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
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

const int N = 3e5+10;
ll n;
ll arr[N];

struct node{
	ll maxsum,m,sm;

	node(){
		m = sm = -1e8+7;
		maxsum = m+sm;
	}
	node(ll value){
		m = value;
		sm = -1e8+7;
		maxsum = m + sm;
	}
	void merge(node left, node right){
		std::vector<int> values(4);
		values[0]=left.m;
		values[1]=left.sm;
		values[2]=right.m;
		values[3]=right.sm;
		sort(values.begin(),values.end());
		m = values[3];
		sm  = values[2];
		maxsum = m + sm;
	}
} st[4*N];

void build(ll p, ll l, ll r){
	if (l==r)
	{
		st[p] = node(arr[l]);
		return;
	}
	ll middle = mid(l,r);
	build(left(p),l,middle);
	build(right(p), middle+1, r);
	st[p] =  node();
	st[p].merge(st[left(p)],st[right(p)]);
}

node query(ll p , ll l, ll r,ll x,ll y){

	if (x>r || y<l)
	{
		return node();
	}
	if (l>=x && r<=y)
	{
		return st[p];
	}

	ll mid = (l+r)/2;

	node p1 = query(left(p), l, mid, x, y);
	node p2 = query(right(p),mid+1,r,x,y);
	node n = node();
	n.merge(p1, p2);
	return n;
}

// void printTree(){
// 	printf("Here is the tree: ");
// 	F(i, 1, 4*n){
// 		printf("     %lld and %lld      ",st[i].m,st[i].sm);
// 	}
// 	printf("   End of the tree\n");
// }

void update(ll p, ll l,ll r,ll index,ll value){
	if (l==r)
	{
		st[p]=node(value);
		return;
	}
	ll middle = mid(l,r);
	if (index<=middle)
	{
		update(left(p),l,middle,index,value);
	}else{
		update(right(p), middle+1, r,index,value);
	}
	st[p] = node();
	st[p].merge(st[left(p)],st[right(p)]);
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int q;

	n = nextll();
	F(i, 0, n){
		arr[i] = nextll();
	}
	build(1,0,n-1);
	// printTree();
	q = nextint();

	char type;
	F(i, 0, q){
		scanf(" %c",&type);

		if (type == 'U')
		{
			ll l = nextll();
			ll value = nextll();
			l--;
			update(1, 0, n-1,l, value);
			// printTree();
		}else{
			ll l=nextll(),r=nextll();
			node ns = query(1,0,n-1,l-1,r-1);
			printf("%lld\n",ns.maxsum);
		}
	}
	


	return 0;
}