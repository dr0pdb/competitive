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

const int N = 5002;
ll dp[N][N], pre[N]; // steps and position
int n,a,b,k;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n>>a>>b>>k;
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    
    FOR(pos, 1, n + 1) {
        if(pos == b || pos == a) continue;
        if(abs(a - b) > abs(pos - a)) {
            dp[1][pos] = 1;
            pre[pos] = 1;
        }
    }
    FOR(pos, 2, n + 1) {
        pre[pos] += pre[pos - 1];
    }

    FOR(i, 2, k + 1) {
        FOR(pos, 1, n+1) {
            if(pos == b) continue;
            int lo, hi;
            if(pos > b) {
                hi = n;
                lo = pos - (pos - b - 1)/2;
            } else {
                lo = 1;
                hi = min((ll)n, pos + (b - pos - 1)/2);
            }

            // cout<<pos<<" <- pos, "<<lo<<" "<<hi<<endl;
            dp[i][pos] = ((pre[hi] - pre[lo - 1] + MOD)%MOD - dp[i - 1][pos] + MOD) % MOD;
        }
        pre[0] = 0;
        FOR(pos, 1, n + 1) {
            pre[pos] = (dp[i][pos] + pre[pos - 1]) % MOD;
        }
        // FOR(i, 1, n + 1) {
        //     cout<<pre[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"dp array:\n";
        // FOR(pos, 1, n + 1) {
        //     cout<<dp[i][pos]<<" ";
        // }
        // cout<<endl;
    }
    ll res = 0;
    FOR(pos, 1, n + 1) {
        res += dp[k][pos];
        res %= MOD;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}