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

const int N = 41;
int mat[N][N], cum[N][N]={0}, cnt[N][N]={0}, up[N][N]={0};

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,q; cin>>n>>m>>q;
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		scanf("%1d", &mat[i][j]);
    	}
    }
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		if(mat[i][j]) continue;
    		int curr = 0;
    		RFOR(k, i, 0) {
    			if(!mat[k][j]) curr++;
    			else break;
    		}
    		up[i][j] = curr;
    	}
    }
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		int minm = up[i][j];
    		RFOR(k, j, 0) {
    			minm = min(minm, up[i][k]);
    			cnt[i][j] += minm;
    		}
    		cum[i][j] = cnt[i][j];
    		if(j) cum[i][j] += cum[i][j-1];
    		if(i) cum[i][j] += cum[i-1][j];
    		if(i && j) cum[i][j] -= cum[i-1][j-1];
    	}
    }
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		cout<<cnt[i][j]<<" ";
    	}
    	cout<<endl;
    }
    cout<<"Niger\n";
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		cout<<cum[i][j]<<" ";
    	}
    	cout<<endl;
    }
    int a,b,c,d;
    while(q--) {
    	cin>>a>>b>>c>>d; a--; b--; c--; d--;
    	int ans = cum[c][d];
    	if(a) ans -= cum[a-1][d];
    	if(b) ans -= cum[c][b-1];
    	if(a && b) ans += cum[a-1][b-1];
    	cout<<ans<<endl;
    }

    return 0;
}