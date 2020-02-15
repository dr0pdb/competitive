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

const int nax = 1005;
int arr[nax];
ll dp[nax][nax]; // no of ways to select j people from first i with ith being the last

ll factorial[nax];
void pre() {
    factorial[0] = 1;
    for (int i = 1; i < nax; i++) {
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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int _n) {
        this->n = _n + 1;
        bit.assign(_n + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
            verify(ret);
        }
        return ret;
    }

    // l and r should be given as 0 based indexes.
    int sum(int l, int r) {
        return (sum(r) - sum(l - 1) + MOD)%MOD;
    }

    // idx as zero based.
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx) {
            bit[idx] += delta;
            bit[idx] %= MOD;
        }
    }
};

int tmp[nax];
map<int,int> m;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    int n,k; cin>>n>>k;
    FOR(i, 0, n) {
        cin>>arr[i];
        tmp[i] = arr[i];
    }
    // coordinate compression.
    sort(tmp, tmp + n);
    int nn = unique(tmp, tmp + n) - tmp;
    FOR(i, 0, nn) m[tmp[i]] = i + 1;
    FOR(i, 0, n) arr[i] = m[arr[i]];
    // FOR(i, 0, n) cerr << arr[i] << " ";
    // cerr << endl;

    // dp
    memset(dp, 0, sizeof(dp));
    FOR(i, 0, n) dp[i][0] = dp[i][1] = 1;
    FOR(j, 2, k + 1) {
        FenwickTree ft(n);
        ft.add(arr[0], dp[0][j-1]);

        FOR(i, 1, n) {
            dp[i][j] = ft.sum(0, arr[i]);
            ft.add(arr[i], dp[i][j-1]);
            // FOR(kk, 0, i) {
            //     if(arr[kk] <= arr[i]) dp[i][j] += dp[kk][j - 1];
            //     verify(dp[i][j]);
            // }
        }
    }
    ll num = 0;
    FOR(i, 0, n) {
        num += dp[i][k];
        verify(num);
    }
    pre();
    ll denom = binomial_coefficient(n, k);
    num *= modInverse(denom, MOD);
    num %= MOD;
    cout<<num;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}