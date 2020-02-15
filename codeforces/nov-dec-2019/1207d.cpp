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

const int MAXN = 3e5+10;
ll factorial[MAXN];
int n;
vii arr;
map<ii,int> cnteqii;
map<int,int> aeq, beq;

void pre() {
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
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

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * modInverse(factorial[k], MOD) % MOD * modInverse(factorial[n - k], MOD) % MOD;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    pre();
    cin>>n; arr.resize(n);
    FOR(i, 0, n) {
        cin>>arr[i].ff>>arr[i].ss;
        cnteqii[arr[i]]++;
        aeq[arr[i].ff]++;
        beq[arr[i].ss]++;
    }
    ll total = factorial[n];
    // deb(total);
    ll inca = 1;
    for(auto itr : aeq) {
        inca *= factorial[itr.ss];
        inca %= MOD;
    }
    // deb(inca);
    ll decb = 1;
    for(auto itr : beq) {
        decb *= factorial[itr.ss];
        decb %= MOD;
    }
    // deb(decb);
    ll incadecb = 0;
    sort(all(arr));
    bool sorted = true;
    FOR(i, 1, n) {
        if(arr[i].ff < arr[i - 1].ff || arr[i].ss < arr[i - 1].ss) {
            sorted = false; break;
        }
    }
    if(sorted) {
        incadecb = 1;
        for(auto itr : cnteqii) {
            incadecb *= factorial[itr.ss];
            incadecb %= MOD;
        }
    }
    // deb(incadecb);
    ll bad = ((inca + decb)%MOD - incadecb + MOD)%MOD;
    cout<<((total - bad + MOD)%MOD);
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}