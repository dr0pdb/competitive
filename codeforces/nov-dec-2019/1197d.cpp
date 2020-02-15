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

const int N = 3e5+5;
ll arr[N], pref[N], best[N];

ll sm(int i, int j) {
    if(i > j) return 0;
    return pref[j] - ((i > 0) ? pref[i-1] : 0);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n,m,k; cin>>n>>m>>k;
    FOR(i, 0, n) {
        cin>>arr[i];
        pref[i] = arr[i] + ((i > 0) ? pref[i - 1] : 0);
        best[i] = 0;
    }
    ll res = 0;
    FOR(len, 1, min(m, n) + 1) {
        res = max(res, sm(0, len - 1) - k);
    }

    FOR(i, 0, n) {
        if(i + 1 >= m) {
            ll ret = sm(i - m + 1, i) - k;
            if(i - m >= 0) ret += best[i - m];
            best[i] = max(best[i], ret);
        }

        FOR(len, 0, m) {
            if(i + len == n) break;
            res = max(res, best[i] + sm(i + 1, i + len) - k * (len > 0));
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}