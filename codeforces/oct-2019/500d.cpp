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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
vi g[N];
vector<iii> elist;
vll cnt;
int n;

int dfs(int curr, int par = -1) {
    int sz = 1;
    for(int idx : g[curr]) {
        int nxt = elist[idx].ss.ss;
        if(nxt == curr) nxt = elist[idx].ss.ff;
        if(nxt == par) continue;
        int subsize = dfs(nxt, curr);
        sz += subsize;
        cnt[idx] = (subsize * 1LL * (n - subsize));
    }
    return sz;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a,b,w; cin>>n;
    cnt.resize(n-1, 0);
    FOR(i, 0, n-1) {
        cin>>a>>b>>w; a--; b--;
        g[a].push_back(elist.size());
        g[b].push_back(elist.size());
        elist.push_back({w, {a, b}});
    }
    dfs(0);
    long double res = 0;
    FOR(i, 0, n-1) {
        // deb(elist[i].ff);
        res += 1.0 * (cnt[i] * 1LL * elist[i].ff * 2)/(n * 1LL * (n-1));
    }
    int q; cin>>q; int idx, wt;
    while(q--) {
        cin>>idx>>wt; idx--;
        res += 1.0 * (cnt[idx] * 1LL * (wt - elist[idx].ff) * 2)/(n * 1LL * (n-1));
        elist[idx].ff = wt;
        coud(3*res, 10); cout<<endl;
    }
    return 0;
}