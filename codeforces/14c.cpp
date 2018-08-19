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

void no() {
	cout<<"NO";
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    map<ii,int> m;
    set<pair<ii,ii>> s;
    int ax, ay, bx, by;

    // minx, maxx, miny, maxy
    int px[2], py[2];
    px[0] = INT_MAX;
    px[1] = INT_MIN;
    py[0] = INT_MAX;
    py[1] = INT_MIN;

    bool ans = true;
    F(i, 0, 4){
		cin>>ax>>ay>>bx>>by;
		m[ii(ax,ay)]+=1;
		m[ii(bx,by)]+=1;

		if(ax == bx && ay == by) {
			ans = false;
		}

		if(s.find(make_pair(ii(ax,ay), ii(bx, by))) != s.end() || s.find(make_pair(ii(bx, by), ii(ax,ay))) != s.end()) {
			ans = false;
		} else {
			s.insert(make_pair(ii(ax,ay), ii(bx, by)));
			s.insert(make_pair(ii(bx, by), ii(ax,ay)));
		}

		px[0] = min(px[0], ax);
		px[1] = max(px[1], ax);
		py[0] = min(py[0], ay);
		py[1] = max(py[1], ay);

		px[0] = min(px[0], bx);
		px[1] = max(px[1], bx);
		py[0] = min(py[0], by);
		py[1] = max(py[1], by);
    }

    if(!ans || m.size() != 4) {
    	no();
    	return 0;
    }

    for(auto itr = m.begin(); itr != m.end(); ++itr) {
    	if(itr -> second != 2) {
    		no();
    		return 0;
    	}
    }

    bool used[4];
    memset(used, false, sizeof(used));

	for(auto itr = m.begin(); itr != m.end(); ++itr) {
		ii p = itr -> first;
    	int a = p.first, b = p.second;
    	if(a == px[0] && b == py[0]) {
    		if(!used[0]) {
    			used[0] = true;
    		} else {
    			no();
    			return 0;
    		}
    	}
    	else if(a == px[0] && b == py[1]) {
    		if(!used[1]) {
    			used[1] = true;
    		} else {
    			no();
    			return 0;
    		}
    	}
    	else if(a == px[1] && b == py[0]) {
    		if(!used[2]) {
    			used[2] = true;
    		} else {
    			no();
    			return 0;
    		}
    	}
    	else if(a == px[1] && b == py[1]) {
    		if(!used[3]) {
    			used[3] = true;
    		} else {
    			no();
    			return 0;
    		}
    	} else {
    		no();
    		return 0;
    	}
    }    

    cout<<"YES";
    return 0;          
}/*
    
*/
 