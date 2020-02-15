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
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int nax = 1e5+5;
int arr[nax]; int n;
ll dp[nax];

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

ll fact[nax];

void pre() {
    fact[0] = 1;
    FOR(i, 1, n) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n; int a;
    FOR(i, 0, n) {
        cin>>a;
        arr[i] = a;
    }
    
    pre();
    dp[0] = 0; dp[1] = (fact[n - 1] * (arr[1] - arr[0]))%MOD;
    FOR(i, 2, n) {
        dp[i] = 0;
        ll curr = modInverse(i, MOD)%MOD;
        ll sm = 0;
        RFOR(j, i - 1, 0) {
            ll tmp = (((arr[i] - arr[j] + MOD)%MOD + sm)*fact[n - 1])%MOD + dp[j]; tmp %= MOD;
            dp[i] += (tmp * curr) % MOD; dp[i] %= MOD;
            sm += (arr[i] - arr[j]); sm %= MOD;
        }
        deb(dp[i]);
    }
    FOR(i, 0, n) {
        cout<<(dp[i])%MOD<<" ";
    }
    cout<<endl;
    cout<<dp[n-1];
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}