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
const ll INF = 1e9+5;
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

int tn,n,m,k,s,t;
const int N = 1e5+5;
vii adjlist[N];
vii revadjlist[N];
int dist[2][N];

void dijkstra(int type, int source, vii adj[]) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;  // dist, vertex
	pq.push(ii(0, source));
	dist[type][source] = 0;
	while(!pq.empty()) {
		ii curr = pq.top(); pq.pop();
		int u = curr.second, d = curr.first;
		if (dist[type][u] < d)
		{
			continue;
		}

		int sz = adj[u].size();
		F(i, 0, sz){
			ii next = adj[u][i];
			int v = next.second;
			int w = next.first;
			if (dist[type][u] + w < dist[type][v])
			{
				dist[type][v] = dist[type][u] + w;
				pq.push(ii(dist[type][v], v));
			}
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>tn;

    while(tn--){
    	cin>>n>>m>>k>>s>>t; s--;t--;
    	F(i, 0, n){
    		adjlist[i].clear();
    		revadjlist[i].clear();
    	}

    	int to,from,wt;
    	F(i, 0, m){
    		cin>>from>>to>>wt;
    		to--; from--;
    		adjlist[from].push_back(ii(wt, to));
    		revadjlist[to].push_back(ii(wt, from));
    	}

		F(i, 0, 2){
			F(j, 0, n){
				dist[i][j] = INF;
			}
		}

		dijkstra(0, s, adjlist);
		dijkstra(1, t, revadjlist);

		int best = INF;
		F(i, 0, n){
			best = min(best, dist[0][i] + dist[1][i]);
		}
		F(i, 0, k){
			cin>>from>>to>>wt;
			from--; to--;
			best = min(best, dist[0][from] + wt + dist[1][to]);
			best = min(best, dist[0][to] + wt + dist[1][from]);
		}

		if (best >= INF)
		{
			cout<<-1<<endl;
		} else {
			cout<<best<<endl;
		}
    }
    return 0;          
}/*
    
*/
 