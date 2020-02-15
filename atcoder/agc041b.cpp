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

const int N = 1e5+5;
ll arr[N],n,m,v,p;

bool ok(int x) {
    if(x < p) return true;
    if(arr[x] + m < arr[p-1]) return false;
    ll tot = (p - 1) * m; // first p - 1 elements.
    tot += (n - 1 - x) * m; // elements less than arr[x].
    tot += m; // own vote for arr[x]
    // from p to x - 1.
    FOR(i, p - 1, x) {
        tot += max(0LL, min(m, arr[x] + m - arr[i]));
    }
    return tot >= m * v;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n>>m>>v>>p;
    FOR(i, 0, n) {
        cin>>arr[i];
    }
    sort(arr, arr + n); reverse(arr, arr + n);
    int lo = 0, hi = n - 1, res = p;
    while(lo <= hi) {
        int mid = (lo + hi)>>1;
        if(ok(mid)) {
            res = max(res, mid + 1);
            lo = mid + 1;
        } else hi = mid - 1;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}