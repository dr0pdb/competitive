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

const int N = 1001;
ll pre[N][N]={0}, suff[N][N]={0}, pal[N][N]={0}, lcp[N][N]={0};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s; ll n;
    cin>>s; n = s.size();
    ll ans = 0;
    FOR(i, 0, n) {
    	pal[i][i] = 1;
    	suff[i][i] = pre[i][i] = 2;
    	if(i) {
    		// so that I don't have to handle bases when j < i.
    		pal[i][i-1] = suff[i][i-1] = pre[i][i-1] = 1;
    	}
    }
    FOR(i, 0, n) {
    	FOR(j, i+1, n) {
    		lcp[i][j] = (s[i] == s[j]) * (1 + ((i > 0 && j + 1 < n) ? lcp[i-1][j+1] : 0));
    	}
    }
    FOR(len, 1, n) {
    	for (int i = 0; i + len < n; ++i) {
			pal[i][i+len] = (s[i] == s[i+len]) * (pal[i+1][i + len - 1]);
			pre[i][i+len] = pal[i][i+len] + pre[i][i+len-1];
			suff[i][i+len] = pal[i][i+len] + suff[i+1][i+len];
    	}
    }
    FOR(i, 0, n) {
    	FOR(j, i+1, n) {
    		ans += (lcp[i][j]) * (suff[i+1][j-1] + pre[i+1][j-1] - 1);
    	}
    }
    cout<<ans;
    return 0;
}