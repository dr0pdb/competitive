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

/*
    dp[i+1] = dp[i] + 2 + (dp[i] - dp[p[i]]);
    To reach i + 1, we first reach i. At that time, it will have odd parity.
    So we'll have to visit p[i] first.
    After that we'll come back to i from p[i]. Total steps for that = dp[i] - dp[p[i]]
    so total steps = dp[i] + 1(going to p[i]) + (dp[i] - dp[p[i]]) + 1(from i to i + 1) 
*/
const int N = 1e3+5;
int n;
ll dp[N],p[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    dp[1] = 0;
    cin>>n;
    FOR(i, 1, n+1) cin>>p[i];
    FOR(i, 2, n+2) {
        dp[i] = ((2*dp[i-1])%MOD - dp[p[i-1]] + 2 + MOD) % MOD;
    }
    cout<<dp[n+1];
    return 0;
}