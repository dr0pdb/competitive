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
const ll INF = 1e18+5;
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
ll arr[N], mina[N], vala[N], sm[N], ans = 0;
bool allgone = false;
vi g[N];
int childs[N], n;

ll lcm(int a, int b) {
    a /= __gcd(a, b);
    if(a > INF / b) {
        allgone = true;
        return a;
    }
    a *= b;
    return a;
}

void dfs(int curr, int par = -1) {
    sm[curr] = arr[curr]; 
    childs[curr] = 0;
    mina[curr] = 1; 
    vala[curr] = arr[curr];

    ll val = INF;
    for(int nxt : g[curr]) {
        if(nxt == par) continue;
        childs[curr]++;
        dfs(nxt, curr);
        sm[curr] += sm[nxt];
        mina[curr] = lcm(mina[curr], mina[nxt]);
        val = min(val, vala[nxt]);
    }

    if(childs[curr]) {
        vala[curr] = val / mina[curr] * mina[curr] * childs[curr]; // max must be div by lcm of childs.

        if(vala[curr] == 0) {
            allgone = true; // have to delete all of them.
            return;
        }

        if(mina[curr] > INF / childs[curr]) {
            allgone = true;
            return;
        }

        mina[curr] *= childs[curr];
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n; int u,v;
    ll total = 0;
    FOR(i, 0, n) {
        cin>>arr[i];
        total += arr[i];
    }
    FOR(i, 1, n) {
        cin>>u>>v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    if(allgone) {
        cout<<total;
        return 0;
    } else {
        cout<<total - vala[0];
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}