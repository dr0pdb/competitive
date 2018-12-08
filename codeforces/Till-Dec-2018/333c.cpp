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
const ll MOD = 1000000009;
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

struct node
{
	int td,bd;
	bool bv,tv;
	node() {
		td = INF;
		bd = INF;
		bv = false;
		tv = false;
	}
};

bool cmp(node a, node b) {
	if(a.td != b.td) 
		return a.td <= b.td;
	return a.bd <= b.bd;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    const int N = 405;
    int n,m,u,v;
    cin>>n>>m;

   	vi rail[N], bus[N];
   	bool railc[N][N];
   	memset(railc, false, sizeof(railc));
   	F(i, 0, m) {
   		cin>>u>>v;
   		u--; v--;
   		rail[u].push_back(v);
   		rail[v].push_back(u);
   		railc[u][v]=true;
   		railc[v][u]=true;
   	}

   	F(i, 0, n) {
   		F(j, i+1, n) {
   			if(!railc[i][j]) {
   				bus[i].push_back(j);
   				bus[j].push_back(i);
   			}
   		}
   	}

   	vector<node> val(n);
   	queue<int> q;
   	q.push(0);
   	val[0].td=0; val[0].bv = true;
   	val[0].bd=0; val[0].tv = true;

   	while(!q.empty()) {
   		int curr = q.front(); q.pop();

   		F(i, 0, rail[curr].size()) {
   			int next = rail[curr][i];
   			if(!val[next].tv) {
   				val[next].tv = true;
   				val[next].td = val[curr].td + 1;
   				q.push(next);
   			}
   		}
   	}

   	q.push(0);
   	while(!q.empty()) {
   		int curr = q.front(); q.pop();

   		F(i, 0, bus[curr].size()) {
   			int next = bus[curr][i];
   			if(!val[next].bv) {
   				val[next].bv = true;
   				val[next].bd = val[curr].bd + 1;
   				if(val[next].bd == val[next].td) {
   					val[next].bd++;
   				}
   				q.push(next);
   			}
   		}
   	}

   	// sort(val.begin(), val.end(), cmp);
   	if(val[n-1].bv && val[n-1].tv) {
   		cout<<max(val[n-1].td, val[n-1].bd);
   	} else {
   		cout<<-1;
   	}


    return 0;          
}/*
    
*/
