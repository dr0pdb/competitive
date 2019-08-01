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
int mat[N][N], vals[4][N][N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m; cin>>n>>m;
    FOR(i, 1, n+1) {
    	FOR(j, 1, m+1) {
    		cin>>mat[i][j];
    	}
    }
    memset(vals, 0, sizeof(vals));
    FOR(i, 1, n+1) {
    	FOR(j, 1, m+1) {
    		vals[0][i][j] = mat[i][j] + max(vals[0][i-1][j], vals[0][i][j-1]);
    	}
    }
    FOR(i, 1, n+1) {
    	RFOR(j, m, 1) {
    		vals[1][i][j] = mat[i][j] + max(vals[1][i-1][j], vals[1][i][j+1]);
    	}
    }
    RFOR(i, n, 1) {
    	FOR(j, 1, m+1) {
    		vals[2][i][j] = mat[i][j] + max(vals[2][i+1][j], vals[2][i][j-1]);
    	}
    }
    RFOR(i, n, 1) {
    	RFOR(j, m, 1) {
    		vals[3][i][j] = mat[i][j] + max(vals[3][i+1][j], vals[3][i][j+1]);
    	}
    }
    int ans = 0;
    FOR(i, 2, n) {
    	FOR(j, 2, m) {
    		ans = max(ans, max(vals[0][i-1][j] + vals[3][i+1][j] + vals[2][i][j-1] + vals[1][i][j+1],
                        vals[0][i][j-1] + vals[3][i][j+1] + vals[2][i+1][j] + vals[1][i-1][j]));
    	}
    }
    cout<<ans;
    return 0;
}