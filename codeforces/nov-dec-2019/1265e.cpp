#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 998244353;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
int n;
ll p[N], pref[N], p100[N];

void pre() {
    p100[0] = 1;
    FOR(i, 1, N) {
        p100[i] = p100[i-1] * 100;
        p100[i] %= MOD;
    }
}

ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m){
	return power(a,m-2,m);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
   
    cin>>n;
    pre();
    FOR(i, 0, n) {
        cin>>p[i];
        pref[i] = p[i];
        if(i) {
            pref[i] *= pref[i-1];
            pref[i] %= MOD;
        }
    }
    ll num = (pref[n-1] * n)%MOD;
    RFOR(i, n-1, 0) {
        int pp = (n - 1 - i);
        ll curr = p100[pp];
        curr *= (100 - p[i]); curr %= MOD;
        curr *= (i + 1); curr %= MOD;
        if(i) {
            curr *= pref[i - 1]; curr %= MOD;
        }
        num += curr; num %= MOD;
    }
    ll denom = p100[n];
    RFOR(i, n - 1, 0) {
        int pp = (n - 1 - i);
        ll curr = p100[pp];
        curr *= (100 - p[i]); curr %= MOD;
        if(i) {
            curr *= pref[i - 1]; curr %= MOD;
        }
        denom = (denom - curr + MOD) % MOD;
    }
    num *= modInverse(denom, MOD);
    num %= MOD;
    cout<<num;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}