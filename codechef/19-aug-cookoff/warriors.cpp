#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e18+1;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
ll arr[N];
lll dp[N];
vll d;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,q; cin>>t;
    while(t--) {
    	cin>>n>>q;
    	FOR(i, 0, n) {
    		cin>>arr[i];
    	}
    	sort(arr, arr+n);
        dp[0] = {arr[0], 0};
        ll p2 = 2;
        FOR(i, 1, n) {
            if (dp[i-1].ss >= arr[i])
            {
                dp[i].ff = dp[i-1].ff;
                dp[i].ss = min(INF, 2*(dp[i-1].ss - arr[i]));    
            } else {
                ll extra_needed = arr[i] - dp[i-1].ss;
                ll extra_needed_start = (extra_needed + p2 - 1)/ p2; // p2 - 1 added to get ceiling.
                dp[i].ff = dp[i-1].ff + extra_needed_start;
                dp[i].ss = min(2 * (dp[i-1].ss + extra_needed_start * p2 - arr[i]), INF);
            }
            if (p2 < INF)
            {
                p2 <<= 1;
            }
        }
        d.clear(); d.resize(n);
        FOR(i, 0, n) {
            d[i] = dp[i].ff + (dp[i].ss == 0);
        }

        ll x;
        while(q--) {
            cin>>x;
            cout<<distance(d.begin(), upper_bound(d.begin(), d.end(), x))<<endl;
        }
    }

    return 0;
}