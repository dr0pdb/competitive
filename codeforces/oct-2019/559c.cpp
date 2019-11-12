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

const ll MOD = 1000000007;
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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int MAXN = 2e5+5;
ll factorial[MAXN], inverse[MAXN];

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

void pre() {
    factorial[0] = 1LL; inverse[0] = modInverse(factorial[0], MOD);
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inverse[i] = modInverse(factorial[i], MOD);
    }
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

vii blacks;

bool cmp(ii a, ii b) {
    if(a.ff == b.ff) return a.ss < b.ss;
    return a.ff < b.ff;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    pre();
    int h,w,n,x,y; cin>>h>>w>>n;
    blacks.resize(n);
    FOR(i, 0, n) {
        cin>>x>>y; x--; y--;
        blacks[i] = {x, y};
    }
    blacks.push_back({h-1, w-1}); n++;
    sort(all(blacks), cmp);
    ll dp[n];
    FOR(i, 0, n) {
        dp[i] = binomial_coefficient(blacks[i].ff + blacks[i].ss, blacks[i].ff);
        ll subtract = 0;
        FOR(j, 0, i) {
            ll dx = blacks[i].ff - blacks[j].ff;
            ll dy = blacks[i].ss - blacks[j].ss;
            if(dx < 0 || dy < 0) continue;
            subtract += (dp[j] * binomial_coefficient(dx + dy, dx))%MOD;
            subtract %= MOD;
        }
        dp[i] = (dp[i] - subtract + MOD) % MOD;
    }
    cout<<dp[n-1];
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}