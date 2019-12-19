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
const ll INF = 1e16+5;
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

const int N = 1e5+5;
ll dp[N];
ll v[N], c[N], a, b;
int n,q;

void solve() {
    FOR(i, 0, N) dp[i] = -INF;

    lll maxm = {0, -1}, smaxm = {0, -1};
    FOR(i, 0, n) {
        int col = c[i];
        if(dp[col] > -INF)
            dp[col] = max(dp[col], dp[col] + a * v[i]);

        ll othermax = maxm.first;
        if(maxm.ss == col) {
            othermax = smaxm.ff;
        }

        dp[col] = max(dp[col], othermax + b * v[i]);

        if(col == maxm.ss) {
            maxm.ff = max(maxm.ff, dp[col]);
        } else if(dp[col] > maxm.ff) {
            swap(maxm, smaxm);
            maxm = {dp[col], col};
        } else if(dp[col] > smaxm.ff) {
            smaxm = {dp[col], col};
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>q;
    FOR(i, 0, n) cin>>v[i];
    FOR(i, 0, n) cin>>c[i];

    FOR(i, 0, q) {
        cin>>a>>b;
        solve();
        cout<<max(0LL, *max_element(dp, dp+N))<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}