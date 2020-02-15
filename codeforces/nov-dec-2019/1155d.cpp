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
const ll INF = 1e17+5;
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

const int N = 3e5+5;
ll dp[N][3]; // not mult, continue, done but can't continue.
ll n,x, arr[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>x;
    FOR(i, 0, n) {
        cin>>arr[i];
    }
    dp[0][0] = max(0LL, arr[0]); dp[0][1] = max(0LL, x * arr[0]); dp[0][2] = -INF;
    ll res = 0;
    res = max(res, dp[0][0]); res = max(res, dp[0][1]);
    FOR(i, 1, n) {
        FOR(status, 0, 3) {
            if(status == 0) {
                dp[i][status] = max(0LL, arr[i] + dp[i-1][0]);
            } else if(status == 1) {
                dp[i][status] = max(0LL, x * arr[i] + max(dp[i-1][0], dp[i-1][1]));
            } else {
                dp[i][status] = max(0LL, arr[i] + max(dp[i-1][1], dp[i-1][2]));
            }

            res = max(res, dp[i][status]);
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}