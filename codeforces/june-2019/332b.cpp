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

const int N = 2e5+1;
ll arr[N], maxi[N], maxm[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,k,sum=0,mx=0,mxi; cin>>n>>k;
    FOR(i, 0, n) cin>>arr[i];
    RFOR(i, n-1, 0) {
    	sum += arr[i];
    	if(i + k < n) sum -= arr[i+k];
    	if(sum >= mx) {
    		mx = sum;
    		mxi = i;
    	}
    	if(i > n - k) {
    		maxi[i] = -1;
    		maxm[i] = 0;
    	} else {
    		maxi[i] = mxi;
    		maxm[i] = mx;
    	}
    }
    // FOR(i, 0, n) {
    // 	cout<<maxi[i]<<" "<<maxm[i]<<endl;
    // }
    // cout<<"Nigger\n";
    ll a,b; sum = 0, mx = 0;
    FOR(i, 0, n-k) {
    	sum += arr[i];
    	if(i - k >= 0) sum -= arr[i-k];
    	if(i < k-1) continue;
    	if(sum + maxm[i+1] > mx) {
    		mx = sum + maxm[i+1];
    		a = i - k + 1;
    		b = maxi[i+1];
    	}
    }
    cout<<a+1<<" "<<b+1;

    return 0;
}