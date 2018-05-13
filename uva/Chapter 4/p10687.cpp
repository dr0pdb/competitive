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
const ll INF = LONG_LONG_MAX;
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

const int N = 1005;
int n;
vii stations;
int adjlist[N][2];
bool visited[N];
int cnt;

int dist(ii p1, ii p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

void dfs(int curr){
	visited[curr] = true;
	cnt++;
	F(i, 0, 2){
		int next = adjlist[curr][i];
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	while(cin>>n && n){
		stations.clear();
		stations.resize(n);
		F(i, 0, n){
			cin>>stations[i].first>>stations[i].second;
		}

		F(i, 0, n){
			int mina = INT_MAX, minb = INT_MAX;
			int ca = -1, cb = -1;
            for (int j = 0; j < n; j++)
                if (i != j) {
                    int d = dist(stations[i], stations[j]);
                    if (d <= mina) {
                        minb = mina;
                        mina = d;
                        cb = ca;
                        ca = j;
                    } else if (d < minb || (d == minb && ((stations[j].first < stations[cb].first) || (stations[j].first == stations[cb].first && (stations[j].second < stations[cb].second))))) {
                        minb = d;
                        cb = j;
                    }
                }
            adjlist[i][0] = ca;
            adjlist[i][1] = cb;
		}

		memset(visited, false, sizeof(visited));
		cnt = 0;
		dfs(0);
		if (cnt == n)
		{
			cout<<"All stations are reachable.\n";
		} else {
			cout<<"There are stations that are unreachable.\n";
		}
	}	


    return 0;          
}/*
    
*/
 