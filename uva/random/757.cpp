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

ll n,h,f[26],t[26],d[26];
ll dp[26][195][195];
bool mov[26][195][195];

ll solve(ll curr_index, ll curr_time, ll start_time) {
    if(curr_time >= h || curr_index > n) {
        return 0L;
    }

    if(dp[curr_index][curr_time][start_time] != -1) {
        return dp[curr_index][curr_time][start_time];
    }

    ll ret;

    // stay here.
    ret = max(f[curr_index]-((curr_time-start_time)*d[curr_index]), 0LL) + solve(curr_index, curr_time+1, start_time);

    ll mv = -1;
    // move to next one if it exists.
    if(curr_index != n && curr_time+t[curr_index] < h) {
        mv = solve(curr_index+1, curr_time+t[curr_index], curr_time+t[curr_index]);
        
        if(mv > ret) {
            ret = mv;
            mov[curr_index][curr_time][start_time]=true;
        }
    }

    return dp[curr_index][curr_time][start_time] = ret;
}

ll total_time[26];

void buildOutput(ll curr_index, ll curr_time, ll start_time) {
    if(curr_time >= h) {
        return;
    }

    if(mov[curr_index][curr_time][start_time]) {
        buildOutput(curr_index+1, curr_time+t[curr_index], curr_time+t[curr_index]);
    } else {
        total_time[curr_index]+=5;
        buildOutput(curr_index, curr_time+1, start_time);
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.

    bool flag = false;
    while(cin>>n && n) {
        if(flag) {
            cout<<endl;
        }
        flag = true;
    	cin>>h; h *= 12;
    	F(i, 1, n+1) {
    		cin>>f[i];
    	}

    	F(i, 1, n+1) {
    		cin>>d[i];
    	}

    	F(i, 1, n) {
    		cin>>t[i];
    	}

    	t[0]=0;
        memset(dp, -1, sizeof(dp));
        memset(mov, false, sizeof(mov));

        ll ans = solve(1, 0, 0);
        memset(total_time, 0, sizeof(total_time));

        buildOutput(1, 0, 0);
        F(i, 1, n+1) {
            if(i != 1) {
                cout<<", ";
            }
            cout<<total_time[i];
        }
        cout<<endl<<"Number of fish expected: "<<ans<<endl;
    }

    return 0;          
}/*
    
*/
 