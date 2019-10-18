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
/*----------------------------------------------------------------------*/

const int N = 3e5+1;
ll dp[N][3]; int n;
int a[N],b[N];

ll solve(int idx, int preva) {
    if(idx == n) return 0;
    ll &res = dp[idx][preva];
    if(res >= 0) return res;
    res = 1e18+1;

    FOR(inc, 0, 3) {
        int nval = a[idx] + inc;
        if(idx == 0 ||nval != a[idx - 1] + preva) {
            res = min(res, inc *  b[idx] + solve(idx + 1, inc));
        }
    }

    return res;
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q; cin>>q;
    while(q--) {
        scanf("%d", &n);
        FOR(i, 0, n) {
            scanf("%d %d", &a[i], &b[i]);
            dp[i][0] = dp[i][1] = dp[i][2] = -1;
        }
        ll res = solve(0,0);
        printf("%lld\n", res);
    }
    return 0;
}