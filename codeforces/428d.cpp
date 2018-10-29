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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    const int N = 1e6+5;
    ll n;
    cin>>n;

    ll arr[n], ex[N], dp[N],cnt[N];
    memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));

	ex[0]=1;
	F(i, 1, N) {
		ex[i] = ex[i-1]*2;
		ex[i] %= MOD;
	}

	ll maxm = INT_MIN, ans = 0;
    F(i, 0, n) {
    	cin>>arr[i];
		
		for(long long j = 2; j*j <= arr[i]; j++) {
			if(arr[i] % j == 0) {
				cnt[j]++;
				if(arr[i]/j != j)
                    cnt[arr[i]/j]++;
			}
		}
		cnt[arr[i]]++;
		maxm = max(arr[i], maxm);
    }	

    RF(i, maxm, 2) {
    	if(cnt[i]) {
    		dp[i] = cnt[i] * ex[cnt[i]-1];
    		dp[i] %= MOD;

    		ll minus = 0;
    		if(i <= maxm/2) {
    			for(ll a = 2*i; a <= maxm; a+=i) {
    				minus += dp[a];
    				minus %= MOD;
    			}
    		}

    		dp[i] = (dp[i] - minus + MOD) % MOD;
    		ans += (i * dp[i]);
    		ans %= MOD;
    	}
    }

    cout<<ans;

    return 0;          
}/*
   The below one works but uses too much memory. 
*/

// int main(){
//     std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
//     int n;
//     cin>>n;

//     int arr[n];
//     F(i, 0, n) {
//     	cin>>arr[i];
//     }

//     unordered_map<int,vi> m[2];
//     m[0][0].push_back(0);
//     int t = 1;
//     F(i, 1, n+1) {
// 		int num = arr[i-1],g;
// 		for(auto itr = m[1-t].begin(); itr != m[1-t].end(); ++itr) {
// 			// not taking.
// 			F(j, 0, itr->second.size()) {
// 				m[t][itr->first].push_back(itr->second[j]);
// 			}

// 			// taking.
// 			g = gcd(num, itr->first);
// 			F(j, 0, itr->second.size()) {
// 				m[t][g].push_back(itr->second[j]+1);
// 			}
// 		}
// 		m[1-t].clear();
// 		t = 1 - t;
//     }

//     ll ans = 0;
//     for(auto itr = m[1-t].begin(); itr != m[1-t].end(); ++itr) {
// 		int g = itr -> first;
// 		if(g <= 1) continue;
// 		F(j, 0, itr->second.size()) {
// 			ans += g*(itr -> second[j]);
// 			ans %= MOD;
// 		}
// 	}
// 	cout<<ans;
//     return 0;          
// }/*
    
// */