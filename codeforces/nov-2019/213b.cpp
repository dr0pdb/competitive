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

const int MAXN = 105;

ll comb[MAXN][MAXN];
int n, a[MAXN];

void findCoeff(){
	comb[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
    	comb[i][0] = 1;
    	for (int j = 1; j <= i; j++) {
      		comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
    	}
	}	
}

ll ncr(int n, int r) {
    if(r > n) return 0;
    return comb[n][r];
}

ll dp[101][10];

ll solve(int len, int dig) {
    if(len < a[dig]) return 0;
    if(dig == 9) return 1;
    ll &res = dp[len][dig];
    if(res >= 0) return res;
    res = 0;

    if(dig == 0) {
        FOR(cnt, a[dig], len + 1) {
            res += (solve(len - cnt, dig + 1) * ncr(len -1, cnt))%MOD;
            res %= MOD;
        }
    } else {
        FOR(cnt, a[dig], len + 1) {
            res += (solve(len - cnt, dig + 1) * ncr(len, cnt))%MOD;
            res %= MOD;
        }
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n;
    FOR(i, 0, 10) cin>>a[i];
    findCoeff();
    memset(dp, -1, sizeof(dp));
    ll res = 0;
    FOR(i, 1, n + 1) {
        res += solve(i, 0);
        res %= MOD;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}