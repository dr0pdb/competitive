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

const int N = 30001;
ll n,k, c[N], sm;

bool ok(ll col) {
    vector<ll> left(n);
    ll cnt = 0;
    FOR(i, 0, n) {
        ll extra = (i > 0) ? left[i - 1] : 0;
        ll available = c[i] + extra;
        ll curr = available / col;
        cnt += curr;
        ll extrasused = min(extra, col*curr);
        left[i] = c[i] - (col*curr - extrasused);
        // cout<<i<<" <-index "<<cnt<<" "<<left[i-1]<<" "<<left[i]<<endl;
    }
    return cnt >= k;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t;cin>>t;
    while(t--) {
        cin>>n>>k; sm = 0;
        FOR(i, 0, n) {
            cin>>c[i];
            sm += c[i];
        }

        ll lo = 1, hi = sm / k, res = 0;
        // deb(hi);
        while(lo <= hi) {
            ll mid = (lo + hi) >> 1;
            // deb(mid);
            if(ok(mid)) {
                res = max(res, mid * k);
                lo = mid + 1;
            } else hi = mid - 1;
        }

        cout<<res<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}