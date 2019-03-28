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

const int N = 200001;
ll tmp,cnt[N],freq[N],maxm=-1;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    memset(cnt, 0, sizeof(cnt));
    memset(freq, 0, sizeof(freq));

    FOR(i, 0, n) {
    	cin>>tmp;
    	cnt[tmp]++;
    	maxm = max(tmp, maxm);
    }

    freq[0]=cnt[0];
    FOR(i, 1, N) {
    	freq[i] = freq[i-1] + cnt[i];
    }

    ll ans = 0;
    FOR(x, 1, 200001) {
    	if(cnt[x]) {
    		ll curr = 0;
    		for(int val = x; val <= maxm; val += x) {
    			curr += val * (freq[min(maxm, val + x - 1)] - freq[val-1]);
    		}
    		ans = max(ans, curr);
    	}
    }
    cout<<ans;

    return 0;
}