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

const int N = 1<<18;
ll n;
ll arr[N];

// vi lazy(4*N,0);

struct node{
	ll bit;

	node(){
		bit = 0;
	}
	node(int value){
		bit = value;
	}
	//last=0-do xor , 1 - do or
	void merge(node left, node right,int last){
		if (!last)
		{
			bit = left.bit^right.bit;
			// printf("Taking xor of %lld and %lld as %lld\n", left.bit,right.bit,bit);
		}else{
			bit = left.bit|right.bit;
			// printf("Taking or of %lld and %lld as %lld\n", left.bit,right.bit,bit);
		}
		
	}
} st[4*N];

void build(ll p, ll l, ll r,int last){
	if (l==r)
	{
		// printf("last is %d\n", last);
		node n = node(arr[l]);
		st[p] = n;
		return;
	}

	build(left(p),l,(l+r)/2,1-last);
	build(right(p),(l+r)/2+1,r,1-last);

	node n = node();
	n.merge(st[left(p)],st[right(p)],last);
	st[p] = n;
}

void update(ll p , ll l , ll r , ll index, ll value,int last){
	if (l==r)
	{
		st[p].bit = value;
		return;
	}

	ll mid = (l+r)/2;
	if (index<=mid)
	{
		update(left(p), l, mid, index, value,1-last);
	}else{
		update(right(p),mid+1,r,index,value,1-last);
	}
	
	node n;
	n.merge(st[left(p)],st[right(p)],last);
	st[p]=n;
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	ll m,temp;
	temp = nextll();
	n = 1<<temp;
	m = nextll();

	F(i, 0, n){
		arr[i] = nextll();
	}
	if(temp%2==0){
		build(1,0,n-1,0);
	}else{
		build(1,0,n-1,1);
	}
	// printf("\n");
	while(m--){
		ll index=nextll(),value=nextll();
		index--;
		// printf("Index- %lld Value - %lld\n", index,value);
		if (temp%2==0)
		{
			update(1,0,n-1,index,value,0);
		}else{
			update(1,0,n-1,index,value,1);
		}
		
		printf("%lld\n", st[1].bit);
	}

	return 0;
}