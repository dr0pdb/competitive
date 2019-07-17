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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,k[11],p[11],status[11],tmp;
    vi sk[11];
    cin>>n>>m;
    FOR(i, 0, m) {
    	cin>>k[i];
    	FOR(j, 0, k[i]) {
    		cin>>tmp; tmp--;
    		sk[i].push_back(tmp);
    	}
    }
    FOR(i, 0, m) cin>>p[i];
    int ans = 0;
    FOR(i, 0, (1<<n)) {
    	memset(status, 0, sizeof(status));
    	FOR(j, 0, n) {
    		if(i & (1 << j)) {
    			status[j] = 1;
    		}
    	}
    	bool poss = true;
    	FOR(j, 0, m) {
    		int cnt = 0;
    		FOR(x, 0, k[j]) {
    			if(status[sk[j][x]]) cnt++;
    		}
    		cnt %= 2;
    		if(cnt != p[j]) {
    			poss = false; break;
    		}
    	}
    	if(poss) ans++;
    }
    cout<<ans;

    return 0;
}