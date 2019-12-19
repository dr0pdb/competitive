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

const int N = 2e5+5;
vector<lll> emps;
ll n, s, sm;

bool ok(ll median) {
    int cntgreater = 0, cnteq = 0;
    vector<ll> assigned(n);
    ll spendings = sm;
    FOR(i, 0, n) {
        assigned[i] = emps[i].ff;
        if(assigned[i] > median) cntgreater++;
        else if(assigned[i] == median) cnteq++;
    }
    int hf = n / 2;
    // if(cntgreater > hf) return false;
    if(cntgreater + cnteq - 1 >= hf) return true;

    RFOR(i, n - 1, 0) {
        if(assigned[i] < median && emps[i].ss >= median) {
            spendings += (median - assigned[i]);
            if(spendings > s) return false;
            assigned[i] = median;
            cnteq++;
            if((cntgreater + cnteq - 1) >= hf) return true;
        }
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    int t; cin>>t;
    while(t--) {
        emps.clear();
        cin>>n>>s; emps.resize(n);
        ll lo = INT_MAX, hi = -1; sm = 0;
        FOR(i, 0, n) {
            cin>>emps[i].ff>>emps[i].ss;
            sm += emps[i].ff;
            lo = min(lo, emps[i].ff);
            hi = max(hi, emps[i].ss);
        }
        sort(all(emps)); ll res = lo;
        // deb(lo); deb(hi);
        while(lo <= hi) {
            ll mid = (hi + lo)>>1;
            if(ok(mid)) {
                res = max(res, mid);
                lo = mid + 1;
            } else hi = mid - 1;
        }
        cout<<res<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}