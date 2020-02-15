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

typedef pair<ll,ii> line; // c, {a, b} for ax - by = c.

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

// ax - by = c
line create(ii p1, ii p2) {
    int x1 = p1.ff, x2 = p2.ff;
    int y1 = p1.ss, y2 = p2.ss;

    int a = y1 - y2, b = x1 - x2;
    int d = gcd(a, b); a /= d, b /= d;
    if (a < 0 || (a == 0 && b < 0))
    {
        a = -a;
        b = -b;
    }
    std::pair<int,int> slope(a, b);
    long long c = 1LL * a * x1 - 1LL * b * y1;

    return {c, {a, b}};
}

vii pts;
set<line> ss;
map<ii, int> cnt;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n,x,y; cin>>n; pts.resize(n);
    FOR(i, 0, n) {
        cin>>pts[i].ff>>pts[i].ss;
    }
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            line l = create(pts[i], pts[j]);
            ss.insert(l);
        }
    }
    int nwires = ss.size();
    // deb(nwires);
    ll res = 1LL * nwires * (nwires - 1) / 2;
    for(auto itr : ss) {
        cnt[{itr.ss.ff, itr.ss.ss}]++;
    }
    for(auto itr : cnt) {
        res -= itr.ss * 1LL * (itr.ss - 1) / 2;
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}