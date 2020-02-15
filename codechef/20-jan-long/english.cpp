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

const int nax = 1e5+5;
int n;
string arr[nax];

struct trie {
    int nodes, child[nax][676], count[nax];

    void insert(vi &s) {
        int u = 0;
        for(int a : s) {
            if(!child[u][a]) child[u][a] = nodes++;
            u = child[u][a];
        }
        ++count[u];
    }

    ll dfs(int curr = 0, int pref = 0) {
        ll ret = 0;

        FOR(i, 0, 676) {
            if(child[curr][i]) {
                ret += dfs(child[curr][i], pref + 1);
                count[curr] += count[child[curr][i]];
            }
        }

        while(count[curr] >= 2) {
            count[curr] -= 2;
            ret += pref * 1LL * pref;
        }

        return ret;
    }
} tr;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t;
    while(t--) {
        cin>>n;

        memset(tr.child, 0, sizeof(tr.child[0])*tr.nodes);
        memset(tr.count, 0, 4*tr.nodes);
        tr.nodes = 1;

        FOR(i, 0, n) {
            cin>>arr[i];
            string r = arr[i];
            reverse(all(r));
            vi a;
            FOR(j, 0, arr[i].size()) {
                int val = ((arr[i][j]-'a') * 26) + r[j]-'a';
                a.pb(val);
            }
            tr.insert(a);
        }

        cout<< tr.dfs() << endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}