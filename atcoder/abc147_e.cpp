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

const int N = 81;
bool dp[N][N][2*N*N];
int h,w;
int a[N][N],b[N][N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    int offset = 80*80;
    memset(dp, false, sizeof(dp));
    cin>>h>>w;
    FOR(i, 0, h) {
        FOR(j, 0, w) {
            cin>>a[i][j];
        }
    }
    FOR(i, 0, h) {
        FOR(j, 0, w) {
            cin>>b[i][j];
        }
    }
    FOR(i, 0, h) {
        FOR(j, 0, w) {
            if(i == 0 && j == 0) {
                dp[i][j][offset + b[0][0] - a[0][0]] = true;
                dp[i][j][offset - b[0][0] + a[0][0]] = true;
            } else if(i == 0) {
                FOR(sum, 0, 2*N*N) {
                    if(dp[i][j-1][sum]) {
                        dp[i][j][sum + b[i][j] - a[i][j]] = true;
                        dp[i][j][sum + a[i][j] - b[i][j]] = true;
                    }
                }
            } else if(j == 0) {
                FOR(sum, 0, 2*N*N) {
                    if(dp[i-1][j][sum]) {
                        dp[i][j][sum + b[i][j] - a[i][j]] = true;
                        dp[i][j][sum + a[i][j] - b[i][j]] = true;
                    }
                }
            } else {
                FOR(sum, 0, 2*N*N) {
                    if(dp[i][j-1][sum]) {
                        dp[i][j][sum + b[i][j] - a[i][j]] = true;
                        dp[i][j][sum + a[i][j] - b[i][j]] = true;
                    }
                }
                FOR(sum, 0, 2*N*N) {
                    if(dp[i-1][j][sum]) {
                        dp[i][j][sum + b[i][j] - a[i][j]] = true;
                        dp[i][j][sum + a[i][j] - b[i][j]] = true;
                    }
                }
            }
        }
    }
    int res = INF;
    FOR(sum, 0, 2*N*N) {
        if(dp[h-1][w-1][sum]) {
            res = min(res, abs((int)sum - offset));
        }   
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}