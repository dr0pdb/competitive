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
 
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}
 
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/
 
const int NN = (1 << 20);
const int N = 1e5+5;
int arr[N],n;
ll dp[NN + 5][22], f[NN+5];
bool used[NN];
 
int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
 
    int t; cin>>t;
    while(t--) {
        cin>>n;
        memset(dp, 0, sizeof(dp));
        FOR(i, 0, n) {
            cin>>arr[i];
            dp[arr[i]][0]++;
        }
 
        FOR(mask, 0, (1 << 20) + 1) {
            FOR(i, 1, 21) {
                int idx = i - 1;
                if(mask & (1 << idx)) {
                    dp[mask][i] = dp[mask][i-1] + dp[mask ^ (1 << idx)][i - 1];
                } else {
                    dp[mask][i] = dp[mask][i-1];
                }
            }
 
            f[mask] = dp[mask][20];
        }
        
        ll res = 0;
        FOR(i, 0, n) {
            int in = (1ll<<20)-1-arr[i];
            res += (ll) f[in];
        }
 
        cout<<res<<endl;
    }
 
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}