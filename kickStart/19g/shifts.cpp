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

const int N = 12;
ll n,h;
ll a[N],b[N];
map<pair<ll, int>, ll> dp;
// ll dp[N][(1LL << 24) + 1];

ll solve(int day, int mask) {
    if(day == n) {
        ll ah = 0, bh = 0;
        FOR(i, 0, 24) {
            if(i % 2 == 0) {
                if(mask & (1LL << i)) {
                    ah += a[i/2];
                }
            } else {
                if(mask & (1LL << i)) {
                    bh += b[i/2];
                }
            }
        }
        return (ah >= h && bh >= h);
    }
    auto itr = dp.find({day, mask});
    if(itr != dp.end()) return itr->second;
    ll res = 0;

    int mi = 2*day; int mi2 = mi + 1;
    res += solve(day + 1, (mask | (1LL << mi) | (1LL << mi2)));
    res += solve(day + 1, (mask | (1LL << mi)));
    res += solve(day + 1, (mask | (1LL << mi2)));

    return dp[{day, mask}] = res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t;
    FOR(tn, 1, t+1) {
        cin>>n>>h;
        FOR(i, 0, n) cin>>a[i];
        FOR(i, 0, n) cin>>b[i];
        dp.clear();
        print_case(tn);
        cout<<solve(0, 0)<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}