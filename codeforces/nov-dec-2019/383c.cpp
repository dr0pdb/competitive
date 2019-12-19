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
int n,m,a,b,t,x,val;
int arr[N], in[N], out[N], order[N], timer = -1, depth[N];
vi g[N];

void dfs(int curr) {
    in[curr] = ++timer;
    order[timer] = curr;

    for(int nxt : g[curr]) {
        if(in[nxt] == -1) {
            depth[nxt] = depth[curr] + 1;
            dfs(nxt);
        }
    }

    out[curr] = timer;
}

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // l and r should be given as 0 based indexes.
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    // idx as zero based.
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    FOR(i, 0, n) cin>>arr[i];
    FOR(i, 0, n-1) {
        cin>>a>>b; a--; b--;
        g[a].push_back(b); g[b].push_back(a);
    }
    memset(in, -1, sizeof(in)); depth[0] = 0;
    dfs(0);
    // FOR(i, 0, n) {
    //     cout<<in[i]<<" "<<i<<" "<<out[i]<<endl;
    // }

    FenwickTree ft(n+1);
    while(m--) {
        cin>>t>>x; x--;
        if(t == 1) {
            cin>>val;
            // deb(in[x]); deb(out[x]);
            if(depth[x] & 1) {
                ft.add(in[x], -val);
                ft.add(out[x]+1, val);
            } else {
                ft.add(in[x], val);
                ft.add(out[x]+1, -val);
            }
        } else {
            int additional = ft.sum(in[x]);
            if(depth[x] & 1) {
                cout<<arr[x] - additional<<endl;
            } else {
                cout<<arr[x] + additional<<endl;
            }
        }
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}