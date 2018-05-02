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

const int N = 6000;
int req[N],coins[6] = {5,10,20,50,100,200};
int p[6];
string target;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	F(i, 0, N){
		req[i] = INT_MAX;
	}
	req[0] = 0;
	for (int i = 5; i < N; i+=5)
	{
		F(j, 0, 6){
			if (i >=coins[j])
			{
				req[i] = min(req[i], 1 + req[i - coins[j]]);
			}
		}
	}
	// cout<<"HELLO 1"<<endl;
	while(cin>>p[0]>>p[1]>>p[2]>>p[3]>>p[4]>>p[5] && (p[0] + p[1] + p[2] + p[3] + p[4] + p[5])) {
		cin>>target;
		int tar = 0;
		tar += (target[0]-'0')*100;
		tar += (target[2]-'0')*10;
		tar += (target[3]-'0');
		map<int,int> m;
		// cout<<"HELLO 1"<<endl;
		F(i, 0, p[0]+1) {
			F(j, 0, p[1]+1) {
				F(k, 0, p[2]+1) {
					F(k1, 0, p[3]+1) {
						F(k2, 0, p[4]+1){
							F(k3, 0, p[5]+1){
								int sums = i + j + k + k1 + k2 + k3;
								int value = i*coins[0] + j*coins[1] + k*coins[2] + k1*coins[3] + k2*coins[4] + k3*coins[5];
								if (value < tar)
								{
									continue;
								}
								if (m.find(value) != m.end())
								{
									m[value] = min(m[value], sums);
								} else {
									m[value] = sums;
								}
							}
						}
					}
				}
			}
		}
		// cout<<"HELLO 1"<<endl;
		int ans = INT_MAX;
		for(auto itr = m.begin(); itr != m.end(); ++itr){
			int value = itr -> first;
			int needed = itr->second;
			ans = min(ans, needed + req[value-tar]);
		}
		// cout<<"HELLO 1"<<endl;
		std::cout.width(3); std::cout << std::right << ans << '\n';
	}
    return 0;          
}/*
    
*/
 