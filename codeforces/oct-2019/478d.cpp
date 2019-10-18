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

const int N = 2e5+1;
// const int NN = 850;
// ll dp[NN][N];
ll dp[2][N];
ll r,g,maxh = 0;

// ll solve(int level, int rused) {
//     int gused = ((level - 1)*(level) / 2) - rused;
//     if(rused + level > r && gused + level > g) {
//         return level == maxh + 1;
//     }
   
//     ll &res = dp[level][rused];
//     if(res >= 0) return res;
//     res = 0;
    
//     if(rused + level <= r) {
//         res += solve(level + 1, rused + level); res %= MOD;
//     }

//     if(gused + level <= g) {
//         res += solve(level + 1, rused); res %= MOD;        
//     }
    
//     return res;
// }

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp, 0, sizeof(dp));
    cin>>r>>g;
    while(maxh * (maxh + 1) <= 2 * (r + g)) maxh++;
    maxh--;
    int turn = 0; dp[1][0] = 1;
    FOR(h, 1, maxh+1) {
        FOR(rused, 0, r+1) {
            dp[turn][rused] = 0;
            int gused = h*(h+1)/2 - rused;
            if(gused > g) continue;
            if(rused >= h)
                dp[turn][rused] = dp[1-turn][rused - h];
            if(gused >= h)
                dp[turn][rused] += (dp[1-turn][rused])%MOD;
        }
        turn = 1 - turn;
    }
    ll res = 0;
    FOR(rused, 0, r+1) {
        res += dp[1-turn][rused];
        res %= MOD;
    }
    cout<<res;
    return 0;
}