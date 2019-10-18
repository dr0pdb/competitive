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
int deg[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,m,u,v; cin>>t;
    while(t--) {
        cin>>n>>m;
        FOR(i, 0, n) {
            g[i].clear();
            deg[i] = 0;
        }
        FOR(i, 0, m) {
            cin>>u>>v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        if(m % 2 == 0) {
            cout<<1<<endl;
            FOR(i, 0, n) cout<<1<<" ";
            cout<<endl;
            continue;
        }
        int oddi = -1;
        FOR(i, 0, n) if(deg[i] % 2) oddi = i;
        if(oddi != -1) {
            cout<<2<<endl;
            FOR(i, 0, n) {
                if(i == oddi) cout<<2<<" ";
                else cout<<1<<" ";
            }
        } else {
            cout<<3<<endl;
            int u1, u2;
            FOR(i, 0, n) {
                if(g[i].size()) {
                    u1 = i;
                    u2 = g[i][0];
                    break;
                }
            }
            FOR(i, 0, n) {
                if(i == u1) cout<<1<<" ";
                else if(i == u2) cout<<2<<" ";
                else cout<<3<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}