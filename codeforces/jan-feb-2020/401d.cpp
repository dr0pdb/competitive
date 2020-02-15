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

ll dp[(1 << 18) + 5][105],nn,m;
vi n;
int len;

bool get(int mask, int bit) {
    return (1 << bit) & mask;
}

int setmask(int mask, int bit) {
    return mask | (1 << bit);
}

ll solve(int mask, int md) {
    if(mask == ((1 << len) - 1)) return !md;

    ll &res = dp[mask][md];
    if(res >= 0) return res;    
    res = 0;

    bool used[10] = {false};

    FOR(i, 0, len) {
        if(n[i] == 0 && mask == 0) continue; // no leading zero
        if(used[n[i]] || get(mask, i)) continue;
        res += solve(setmask(mask, i), (md*10 + n[i])%m);
        used[n[i]] = true;
    }

    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>nn>>m;
    while(nn > 0) {
        n.pb(nn % 10);
        nn /= 10;
    }
    len = n.size();
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0);
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}