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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int BLOCK_SIZE = 317;
const int N = 1e5+5;
int arr[N], dp[N], pi[N], rep[N], n, m;

void build_dp(int lo, int hi) {
    RFOR(i, hi, lo) {
        int nxt = i + arr[i];
        if(nxt > hi) {
            dp[i] = 1;
            pi[i] = nxt;
            rep[i] = i;
        } else {
            dp[i] = dp[nxt] + 1;
            pi[i] = pi[nxt];
            rep[i] = rep[nxt];
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    FOR(i, 0, n) cin>>arr[i];

    memset(pi, -1, sizeof(pi));
    for(int i = 0; i < n;) {
        build_dp(i, min(i + BLOCK_SIZE - 1, n-1));
        i += BLOCK_SIZE;
    }
    int tp,a,b;
    while(m--) {
        cin>>tp;
        if(!tp) {
            cin>>a>>b; a--;
            arr[a] = b;
            int lo = a / BLOCK_SIZE * BLOCK_SIZE;
            build_dp(lo, min(n - 1, lo + BLOCK_SIZE - 1));            
        } else {
            cin>>a; a--;
            int steps = 0, lasti = rep[a];
            while(a < n) {
                // deb(a);
                steps += dp[a];
                lasti = rep[a];
                a = pi[a];
            }
            cout<<lasti+1<<" "<<steps<<endl;
        }
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}