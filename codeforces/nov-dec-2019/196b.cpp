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

const int N = 1501;
int n,m,x,y;
char mat[5*N][5*N];
bool visited[5*N][5*N];
int dirx[4] = {0, 0, -1, 1};
int diry[4] = {-1, 1, 0, 0};

bool valid(int nx, int ny) {
    return nx >= 0 && nx < 5*n && ny >= 0 && ny < 5*m;
}

void dfs(ii curr) {
    tie(x,y) = curr;
    FOR(d, 0, 4) {
        int nx = x + dirx[d]; int ny = y + diry[d];
        if(valid(nx, ny) && mat[nx][ny] != '#' && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs({nx, ny});
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    ii start;
    cin>>n>>m;
    FOR(i, 0, 5*n) {
        FOR(j, 0, 5*m) {
            if(i < n && j < m) {
                cin>>mat[i][j];
                if(mat[i][j] == 'S') start = {i + 2*n, j + 2*m};
            }
            mat[i][j] = mat[i%n][j%m];
        }
    }
    memset(visited, false, sizeof(visited));
    visited[start.ff][start.ss] = true;
    dfs(start);
    bool good = false;

    // top and bottom row.
    FOR(mult, 0, 5) {
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                int ni = i + mult * m;
                good |= visited[ni][j]; 
                good |= visited[ni][4*n + j];
            }
        }
    }

    FOR(mult, 0, 5) {
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                int nj = j + mult * n;
                good |= visited[i][nj]; 
                good |= visited[4*m + i][nj];
            }
        }
    }
    
    if(good) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}