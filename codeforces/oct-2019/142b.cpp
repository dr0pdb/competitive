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

const int N = 1e6+1;
int n,m;
vi g[N];

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

#define sq(a) (a)*(a)

int adder[4] = {-2, -1, 1, 2};
int color[N];

void dfs(int row, int col, int &c1, int &c2) {
    // cout<<row<<" visited "<<col<< " "<< color[row * m + col]<<endl;
    int h = row * m  + col;
    FOR(xx, 0, 4) {
        FOR(yy, 0, 4) {
            if(abs(xx) == abs(yy)) continue;
            int ni = row + adder[xx]; int nj = col + adder[yy];
            if(valid(ni,nj)) {
                if(sq(row - ni) + sq(col - nj) == 5) {
                    int nh = ni * m + nj;
                    if(color[nh] == -1) {
                        color[nh] = 1 - color[h];
                        if(color[nh]) c2++;
                        else c1++;
                        dfs(ni, nj, c1, c2);
                    } else {
                        assert(color[nh] == 1 - color[h]);
                    }
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    if(n > m) swap(n,m);
    memset(color, -1, sizeof(color));
    int res = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if(color[i * m + j] == -1) {
                int col1 = 1, col2 = 0;
                color[i * n + j] = 0;
                dfs(i, j, col1, col2);
                res += max(col1, col2);
            }
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}