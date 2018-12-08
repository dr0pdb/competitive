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
#define deb(x )     cerr << #x << " here "<< x << endl; 
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

map<ii,iii> p;
std::vector<string> moves {
	"fill A","fill B","empty A", "empty B", "pour A B", "pour B A"
};
int a,b,t;
map<ii, bool> visited;

ii getNextPoint(ii curr, int ind) {
	int cx = curr.first, cy = curr.second;
	switch(ind) {
		case 0:
			cx = a;
			break;
		case 1:
			cy = b;
			break;
		case 2:
			cx = 0;
			break;
		case 3:
			cy = 0;
			break;
		case 4:
            int tmp;
			if(cx > b-cy) {
                tmp = cy;
                cy = b;
                cx -= (b - tmp);
            } else {
                cy += cx; 
                cx = 0;
            }
			break;
		case 5:
			if(cy > a-cx) {
                tmp = cx;
                cx = a;
                cy -= (a - tmp);
            } else {
                cx += cy; 
                cy = 0;
            }
            break;
	}

	return {cx,cy};
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    while(cin>>a>>b>>t) {
    	p.clear();
    	visited.clear();

    	queue<ii> q;
    	q.push({0,0});
    	p[{0,0}]={-1,{-1,-1}};
    	visited[{0,0}]=true;

    	ii final;
    	while(!q.empty()) {
    		ii curr = q.front(); q.pop();

    		if(curr.first == t || curr.second == t) {
        		final = curr;
    			break;
    		}

    		F(i, 0, 6) {
    			ii next = getNextPoint(curr, i);

    			if(visited.find(next) == visited.end()) {
    				visited[next] = true;
    				q.push(next);
    				p[next]={i, curr};
    			}
    		}
    	}

    	stack<int> s;
    	while(p[final] != make_pair(-1, ii(-1, -1))) {
    		s.push(p[final].first);
    		final = p[final].second;
    	}

    	while(!s.empty()) {
    		int curr = s.top(); s.pop();
    		cout<<moves[curr]<<endl;
    	}
    	cout<<"success\n";
    }


    return 0;          
}/*
    
*/
 