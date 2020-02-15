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

const int MAXN = 40000+10;
ll factorial[MAXN];

void pre() {
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
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
    int n,m,a,b; cin>>n>>m;
    vii e(m);
    vi deg(n);
    vector<vi> g(n);
    vector<unordered_set<int>> ug(n);
    FOR(i, 0, m) {
        cin>>a>>b; a--; b--;
        e[i] = {a, b};
        deg[a]++; deg[b]++;
        g[a].pb(b); g[b].pb(a);
        ug[a].insert(b); ug[b].insert(a);
    }
    ll res = 0;
    FOR(i, 0, m) {
        tie(a, b) = e[i];
        ll cnt1 = deg[a] - 1, cnt2 = deg[b] - 1, common = 0;
        for(int nxt : g[b]) {
            if(ug[a].count(nxt)) common++;
        }
        cnt1 -= common; cnt2 -= common;
        FOR(turn, 0, 2) {
            if(deg[a] >= 4 && deg[b] >= 3) {
                // deb(a); deb(b);
                // deb(cnt1); deb(cnt2); deb(common);
        
                FOR(acommontake, 0, min(3LL, common) + 1) {
                    int auncommontake = 3 - acommontake;
                    if(auncommontake > cnt1) continue;
                    FOR(bcommontake, 0, min(2LL, common - acommontake) + 1) {
                        int buncommon = 2 - bcommontake;
                        if(buncommon > cnt2) continue;

                        // cout<<auncommontake<<" "<<acommontake<<" "<<buncommon<<" "<<bcommontake<<endl;
                        ll cnt = binomial_coefficient(cnt1, auncommontake);
                        cnt *= binomial_coefficient(cnt2, buncommon); cnt %= MOD;
                        cnt *= binomial_coefficient(common, acommontake); cnt %= MOD;
                        cnt *= binomial_coefficient(common - acommontake, bcommontake); cnt %= MOD;
                        res += cnt; verify(res);
                    }
                }
            }
            swap(a, b);
            swap(cnt1, cnt2);
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}