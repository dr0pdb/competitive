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
int n, a;
map<ii, ll> dp;
vi facts[nax];

int _sieve_size;
bitset<100> bs;
vi primes;
unordered_map<int,int> primemap;

vi primeFactors(int N)
{
    vi factors;
    int PF_idx = 0, PF = primes[PF_idx];
    while (PF * PF <= N)
    {
        int cnt = 0;
        while (N % PF == 0)
        {
            N /= PF;
            cnt++;
        }
        if(cnt & 1) factors.pb(primemap[PF]);
        PF = primes[++PF_idx];
    }
    if (N != 1)
        factors.push_back(primemap[N]);

    return factors;
}

void sieve(ll upperbound)
{

    _sieve_size = upperbound + 1;

    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i])
        {

            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

ll solve(int idx, int mask) {
    if(idx == n) return (mask == 0);
    if(dp.count({idx, mask})) return dp[{idx, mask}];
    
    int tmpmask = mask;
    ll res = solve(idx + 1, mask);
    for(auto p : facts[idx]) {
        mask ^= (1 << p); // toggle position p.
    }
    res += solve(idx + 1, mask);
    res %= MOD;
    return dp[{idx, tmpmask}] = res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    sieve(75);
    sort(all(primes));
    FOR(i, 0, primes.size()) {
        primemap[primes[i]] = i;
    }
    cin>>n;
    FOR(i, 0, n) {
        cin>>a;
        facts[i] = primeFactors(a);
    }
    cout<<(solve(0, 0) - 1 + MOD)%MOD;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}