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

const int nax = 1501;
char mat[nax][nax];
int n,m;
ii visited[nax][nax];
bool done[nax][nax];
ii source;
bool res = false;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int mod(int a, int b) {
    a = a % b;
    if(a < 0) a += b;
    return a;
}

void dfs(ii curr) {
    if(res) return;
    int x,y; tie(x, y) = curr;
    // deb(x); deb(y);
    FOR(dir, 0, 4) {
        if(res) return;
        int nx = x + dx[dir]; int ny = y + dy[dir];
        int nxm = mod(nx, n); int nym = mod(ny, m);
        if(mat[nxm][nym] == '#') continue;

        if(!done[nxm][nym]) {
            done[nxm][nym] = true;
            visited[nxm][nym] = {nx, ny};
            dfs({nx, ny});
        } else if(visited[nxm][nym].ff != nx || visited[nxm][nym].ss != ny) {
            // cerr << nxm << " "<< nym<<" "<<nx<<" "<<ny<<endl;
            res = true;
            return;
        }
    }    
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin>>mat[i][j];
            if(mat[i][j] == 'S') source = {i, j};
        }
    }
    memset(done, false, sizeof(done));
    done[source.ff][source.ss] = true;
    visited[source.ff][source.ss] = source;
    dfs(source);
    if(res) cout<<"Yes";
    else cout<<"No";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}