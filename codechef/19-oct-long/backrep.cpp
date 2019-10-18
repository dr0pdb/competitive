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

const int N = 5e5+5;
vi g[N];
ll bacts[N];

void shift(int curr, int p = -1) {
    bool isleaf = true;
    for(int nxt : g[curr]) {
        if(nxt != p) {
            isleaf = false;
            shift(nxt, curr);
        }
    }
    if(!isleaf)
        bacts[curr] = 0;
    if(p >= 0) bacts[curr] += bacts[p];
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,q,u,v;
    cin>>n>>q;
    FOR(i, 1, n) {
        // scanf("%d %d", &u, &v);
        cin>>u>>v;
        u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    FOR(i, 0, n) {
        // scanf("%lld", &bacts[i]);
        cin>>bacts[i];
    }
    char c;
    int k;
    FOR(i, 0, q) {
        shift(0);
        // scanf("%c", &c);
        cin>>c;
        if(c == '+') {
            cin>>v>>k; v--;
            // scanf("%d %d", &v, &k); v--;
            bacts[v] += k;
        } else {
            cin>>v; v--;
            // scanf("%d", &v); v--;
            // printf("%lld\n", bacts[v]);
            cout<<bacts[v]<<endl;
        }
    }
    return 0;
}