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

const int N = 101;
int n, d, arr[N], x[N], y[N];
ll dist[N][N], di, v;
bool used[N];
 
ll distance(int a, int b) {
    return d * 1LL * (abs(x[b] - x[a]) + abs(y[b] - y[a]));
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
 
    cin>>n>>d;
    FOR(i, 0, n - 2) {
        cin>>arr[i + 1];
    }
    FOR(i, 0, n) cin>>x[i]>>y[i];
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if(i == j) continue;
            dist[i][j] = distance(i, j) - arr[i];
        }
    }
    FOR(k, 0, n) {
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if(i != j and j != k and i != k)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);     
            }
        }
    }
    cout << dist[0][n-1] << endl;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}