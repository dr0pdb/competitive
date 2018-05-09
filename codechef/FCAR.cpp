#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const ll INF = 1000000009;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/


const int N = 1e5+5;
vector<pair<ll,ll>> adjlist[2*N];
int n,r;
ll ht[N],c[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>n>>r;
    F(i, 1, n+1){
    	cin>>ht[i];
    }
    F(i, 1, n+1){
    	cin>>c[i];
    	adjlist[i].push_back(make_pair(n+i, c[i]));
    	adjlist[n+i].push_back(make_pair(i, c[i]));
    }

    int x,y;
    F(i, 0, r){
    	cin>>x>>y;
    	if (ht[x] <= ht[y])
            adjlist[x].push_back (make_pair(y, 0));
        if (ht[x] >= ht[y])
            adjlist[n + x].push_back (make_pair (n + y, 0));
        if (ht[y] <= ht[x])
            adjlist[y].push_back (make_pair (x, 0));
        if (ht[y] >= ht[x])
            adjlist[n + y].push_back (make_pair (n + x, 0));
    }

 	adjlist[0].push_back(make_pair (1, c[1]));
    adjlist[0].push_back(make_pair (n + 1, c[1]));
    adjlist[n].push_back(make_pair (2 * n + 1, 0));
    adjlist[2 * n].push_back(make_pair (2 * n + 1, 0));

    // dijkstra
    vll dist(2*N, LONG_LONG_MAX);
    priority_queue<pair<ll,ll>, std::vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push(make_pair(0,0));
    dist[0] = 0;
    while(!pq.empty()) {
    	pair<ll,ll> curr = pq.top(); pq.pop();
    	ll u = curr.second; ll d = curr.first;

    	if (dist[u] < d)
    	{
    		continue;
    	}
    	int sz = adjlist[u].size();
    	F(i, 0, sz){
    		pair<ll, ll> next = adjlist[u][i];
    		ll v = next.first;
    		ll w = next.second;

    		if (dist[u] + w < dist[v])
    		{
    			dist[v] = dist[u] + w;
    			pq.push(make_pair(dist[v], v)); 
    		}
    	}
    }

    if (dist[2*n+1] == LONG_LONG_MAX)
    {
    	cout<<"-1";
    }else {
    	cout<<dist[2*n+1];
    }

    return 0;          
}/*
    
*/
 