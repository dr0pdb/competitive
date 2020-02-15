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

const int N = 1001;
char mat[N][N];
int l[N][N], top[N][N];
int n,m;

const int K = 11;
int logg[N+1];
int st[N][K + 1];

void pre() {
	logg[1] = 0;
	for (int i = 2; i <= N; i++)
    	logg[i] = logg[i/2] + 1;
}

int query(int L, int R) {
	int j = logg[R - L + 1];
	return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    pre();
    cin>>n>>m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin>>mat[i][j];
            l[i][j] = 1;
            top[i][j] = 1;
        }
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if(i && mat[i][j] == mat[i-1][j]) top[i][j] += top[i-1][j];
            if(j && mat[i][j] == mat[i][j-1]) l[i][j] += l[i][j-1];
        }
    }

    // FOR(i, 0, n) {
    //     FOR(j, 0, m) {
    //         cout<<l[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // FOR(i, 0, n) {
    //     FOR(j, 0, m) {
    //         cout<<top[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll res = 0;
    FOR(j, 0, m) {
        for (int i = 0; i < n; i++)
    	    st[i][0] = l[i][j];

	    for (int j = 1; j <= K; j++)
	        for (int i = 0; i + (1 << j) <= N; i++)
	            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

        FOR(i, 0, n) {
            int len = query(i - top[i][j] + 1, i); // max length of subrect.
            
            int sz = top[i][j]; // height = 3 * sz.
            int x = i - top[i][j];
            if(x >= 0 && top[x][j] == sz) {
                len = min(len, query(x - top[x][j] + 1, x));
                x = x - top[x][j];
                if(x >= 0 && top[x][j] >= sz) {
                    len = min(len, query(x - sz + 1, x));
                    res += 1LL * len;
                }
            }
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}