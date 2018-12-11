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

int n,m;

void draw(char newone[][105], int i, int j, int sz) {
	if (!sz)
	{
		return;
	}

	newone[i][j] = '*';

	//top
	int cnt = sz;
	RF(k, i-1, 0) {
		newone[k][j] = '*';
		cnt--;
		if(!cnt) {
			break;
		}	
	}

	//left
	cnt = sz;
	RF(k, j-1, 0) {
		newone[i][k] = '*';
		cnt--;
		if(!cnt) {
			break;
		}	
	}


	//bottom
	cnt = sz;
	F(k, i+1, n) {
		newone[k][j] = '*';
		cnt--;
		if(!cnt) {
			break;
		}
	}

	//right
	cnt = sz;
	F(k, j+1, m) {
		newone[i][k] = '*';
		cnt--;
		if(!cnt) {
			break;
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    char mat[n][m];
    int stars[n][m][4];
    memset(stars, 0, sizeof(stars));

    F(i, 0, n) {
    	F(j, 0, m) {
    		cin>>mat[i][j];
    	}
    }

    F(i, 0, n) {
    	F(j, 0, m) {
    		if(mat[i][j] == '.') {
    			continue;
    		}

    		int cnt = 0;

    		//top
    		RF(k, i-1, 0) {
    			if(mat[k][j] != '*') {
    				break;
    			}
    			cnt++;
    		}

    		stars[i][j][0] = cnt;

    		cnt = 0;

    		//left
    		RF(k, j-1, 0) {
    			if(mat[i][k] != '*') {
    				break;
    			}
    			cnt++;
    		}

    		stars[i][j][1] = cnt;
    		cnt = 0;

    		//bottom
    		F(k, i+1, n) {
    			if(mat[k][j] != '*') {
    				break;
    			}
    			cnt++;
    		}

    		stars[i][j][2] = cnt;
    		cnt = 0;

    		//right
    		F(k, j+1, m) {
    			if(mat[i][k] != '*') {
    				break;
    			}
    			cnt++;
    		}

    		stars[i][j][3] = cnt;
    	}
    }

    vi x,y,sz;
    char newone[105][105];
    memset(newone, '.', sizeof(newone));

    F(i, 0, n) {
    	F(j, 0, m) {
    		int mins = min(stars[i][j][0], stars[i][j][1]);
    		mins = min(mins, stars[i][j][2]);
    		mins = min(mins, stars[i][j][3]);
    		
    		if(mins) {
    			x.push_back(i+1);
    			y.push_back(j+1);
    			sz.push_back(mins);

    			draw(newone, i, j, mins);
    		}
    	}
    }

    F(i, 0, n) {
    	F(j, 0, m) {
    		if(mat[i][j] != newone[i][j]) {
    			cout<<-1;
    			return 0;
    		}
    	}
    }

    cout<<x.size()<<endl;
    F(i, 0, x.size()) {
    	cout<<x[i]<<" "<<y[i]<<" "<<sz[i]<<endl;
    }

    return 0;          
}/*
    
*/