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

ll sq(ll a) {
    return a * a;
}

ll dist(int i, int j, vll &x, vll &y, vll &z) {
    return sq(x[i]-x[j]) + sq(y[i] - y[j]) + sq(z[i] - z[j]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n; cin>>n;
    vll x(n),y(n),z(n);
    FOR(i, 0, n) {
        cin>>x[i]>>y[i]>>z[i];
    }
    vector<tuple<ll,ll,ll>> v;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            v.push_back(make_tuple(dist(i, j, x, y, z), i, j));
        }
    }
    sort(all(v));
    vector<bool> done(n); ll tmp, a, b;
    for(auto curr : v) {
        tie(ignore, a, b) = curr;
        if(!done[a] && !done[b]) {
            cout<<a+1<<" "<<b+1<<endl;
            done[a] = true;
            done[b] = true;
        }
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}