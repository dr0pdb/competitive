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
map<int,ll> g[nax];
int n,m,a,b,c;
ll d,d2;
vector<tuple<int,int,ll>> edges;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    FOR(i, 0, m) {
        cin>>a>>b>>d; a--; b--;
        g[a][b] += d;
    }
    FOR(i, 0, n) {
        vi to_del;

        for(auto &itr : g[i]) {
            tie(b, d) = itr;

            if(!g[b].empty()) {
                auto itr2 = g[b].begin();
                tie(c, d2) = *itr2;

                d = min(d, d2);

                itr.ss -= d; itr2->ss -= d;
                if(i != c)
                    g[i][c] += d;
                if(itr.ss == 0) to_del.pb(b);
                if(itr2->ss == 0) g[b].erase(itr2);
            }
        }

        for(int a : to_del) g[i].erase(a);
    }

    FOR(i, 0, n) {
        for(auto &itr : g[i]) {
            if(itr.ss) {
                if(i != itr.ff)
                    edges.pb({i+1, itr.ff + 1, itr.ss});
            }
        }
    }
    cout<<edges.size()<<endl;
    for(auto itr : edges) {
        tie(a, b, d) = itr;
        cout<<a<<" "<<b<<" "<<d<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}