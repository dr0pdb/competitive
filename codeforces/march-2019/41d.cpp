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

const int N = 105;
int dp[N][N][12],par[N][N][12],mat[N][N], n,m,k;
vector<char> sol; int lastcol;

void printSolution(int x, int y, int p) {
	if(x == n-1) {
		lastcol = y;
		return;
	}

	int val = mat[x][y]%k;
	int tmp = (p - val + k)%k;
	if(par[x][y][p] < 0) {	
		printSolution(x+1, y-1, tmp);
		sol.push_back('R');
	} else {
		printSolution(x+1, y+1, tmp);
		sol.push_back('L');
	}
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    k++;

    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		FOR(p, 0, k) {
    			dp[i][j][p] = INT_MIN;
    		}
    	}
    }
    memset(par, -1, sizeof(par));
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		scanf("%1d", &mat[i][j]);
    	}
    }

    FOR(j, 0, m) {
    	dp[n-1][j][(mat[n-1][j])%k] = mat[n-1][j];
    	// deb(dp[n-1][j][(mat[n-1][j])%k]);
    }

    RFOR(i, n-2, 0) {
    	FOR(j, 0, m) {
    		FOR(p, 0, k) {
    			int val = mat[i][j]%k;
    			int tmp = (p - val + k)%k;
    			if(j) {
    				if(dp[i][j][p] < dp[i+1][j-1][tmp] + mat[i][j]) {
    					dp[i][j][p] = dp[i+1][j-1][tmp] + mat[i][j];
    					par[i][j][p] = -1; // i+1,j-1
    				}
    			}

    			if(j != m-1) {
    				if(dp[i][j][p] < dp[i+1][j+1][tmp] + mat[i][j]) {
    					dp[i][j][p] = dp[i+1][j+1][tmp] + mat[i][j];
    					par[i][j][p] = 1; // i+1,j+1
    				}
    			}
    		}
    	}
    }

    int ans = -1, maxj=-1;
    FOR(j, 0, m) {
    	// deb(dp[0][j][0]);
    	if(ans < dp[0][j][0]) {
    		ans = dp[0][j][0];
    		maxj = j;
    	}
    }
    cout<<ans<<endl;
    if(ans >= 0) {
    	printSolution(0, maxj, 0);
    	cout<<lastcol+1<<endl;
    	FOR(i, 0, sol.size()) {
    		cout<<sol[i];
    	}
    }

    return 0;
}