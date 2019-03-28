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
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

ll arr[5005],dp[2][5005], b[5005], ind=0;
set<ll> s;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>arr[i];
    	s.insert(arr[i]);
    }

    FOR(j, 0, 2) {
    	FOR(i, 0, 5005) {
    		dp[j][i] = LONG_LONG_MIN;
    	}
    }

    for(auto num: s) {
    	b[ind++] = num;
    }

    dp[0][0] = abs(arr[0]-b[0]);
    FOR(i, 1, ind) {
    	dp[0][i] = min(dp[0][i-1], abs(arr[0]-b[i]));
    }
    FOR(i, 1, n) {
    	dp[i&1LL][0] = abs(arr[i]-b[0]) + dp[!(i & 1LL)][0];
    }
    FOR(i, 1, n) {
    	int prev = !(i & 1LL), curr = (i & 1LL);
    	FOR(j, 1, ind) {
    		dp[curr][j] = min(dp[curr][j-1], abs(arr[i]-b[j]) + dp[prev][j]);
     	}
    }
    cout<<dp[(n-1) & 1LL][ind-1];

    return 0;
}