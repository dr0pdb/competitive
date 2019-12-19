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

const int M = 2e5+5;
int m,n,k,t;
int arr[M], l[M], r[M], d[M];

bool possible(int people) {
    int lbound = arr[m - people];
    
    vii segs;
    FOR(i, 0, k) {
        if(d[i] > lbound) segs.push_back({l[i], r[i]});
    }
    sort(all(segs));
    int req_time = 0, lastr = 0;

    FOR(i, 0, segs.size()) {
        if(segs[i].ff <= lastr) {
            req_time += max(0, segs[i].ss - lastr);
            lastr = max(lastr, segs[i].ss);
        } else {
            req_time += (segs[i].ss - segs[i].ff + 1);
            lastr = segs[i].ss;
        }
    }
    req_time = 2 * req_time + n + 1;
    return req_time <= t;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>m>>n>>k>>t;
    FOR(i, 0, m) {
        cin>>arr[i];
    }
    sort(arr, arr + m);
    FOR(i, 0, k) {
        cin>>l[i]>>r[i]>>d[i];
    }
    int lo = 1, hi = m, res = 0;
    while(lo <= hi) {
        int mid = (lo + hi)>>1;
        if(possible(mid)) {
            res = max(res, mid);
            lo = mid + 1;
        } else hi = mid - 1;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}