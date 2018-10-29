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

int n,m,r,c,x,y;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

bool valid(int nx, int ny) {
	return nx>=0 && ny>=0 && nx<n && ny<m;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>r>>c>>x>>y;
    r--; c--;
    char mat[n][m];
    F(i, 0, n) {
    	F(j, 0, m){
    		cin>>mat[i][j];
    	}
    }
	
	int moves[n][m][2]; // 0 = left, 1 = right.
	F(i, 0, n){
		F(j, 0, m){
			moves[i][j][0] = INF;
			moves[i][j][1] = INF;
		}
	}

	moves[r][c][0]=0; moves[r][c][1]=0;
	queue<ii> q;
	q.push(ii(r,c));
	int ans = 0;
	int limit[2]; limit[0] = x, limit[1] = y;
	while(!q.empty()) {
		ii curr = q.front(); q.pop();
		int x = curr.first, y = curr.second;

		F(i, 0, 4) {
			int nx = x + dirx[i], ny = y + diry[i];

			int dir = i/2; // 0 = left, 1 = right;
			if(valid(nx,ny) && mat[nx][ny] == '.') {
				if(i%2) {
					if(min(moves[nx][ny][0], moves[nx][ny][1]) > min(moves[x][y][0], moves[x][y][1])) {
						moves[nx][ny][0] = min(moves[nx][ny][0], min(moves[x][y][0], moves[x][y][1]));
						moves[nx][ny][1] = min(moves[nx][ny][1], min(moves[x][y][0], moves[x][y][1]));
						q.push(ii(nx,ny));
					}
				} else {
					if(moves[nx][ny][dir] > 1 + min(moves[x][y][0], moves[x][y][1]) && 1 + min(moves[x][y][0], moves[x][y][1]) <= limit[dir]) {
						moves[nx][ny][dir] = 1 + min(moves[x][y][0], moves[x][y][1]);
						q.push(ii(nx,ny));
					}
				}
			}
		}
	}

	F(i, 0, n){
		F(j, 0, m){
			if(moves[i][j][0] != INF || moves[i][j][1] != INF) {
				ans++;
			}
		}
	}
	cout<<ans;

    return 0;          
}/*
    
*/