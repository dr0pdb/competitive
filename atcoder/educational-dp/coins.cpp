#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
/*----------------------------------------------------------------------*/

const int N = 3005;
double dp[N][N],p[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    int n;
    cin>>n;

    F(i, 1, n+1) {
    	cin>>p[i];
    }

    dp[0][0]=1.0;
    F(i, 1, n+1) {
    	F(j, 0, i+1) {
    		if(j) {
    			dp[i][j] = (p[i]*dp[i-1][j-1]);
    		}
    		dp[i][j] += (1 - p[i])*dp[i-1][j];
    	}
    }

    double ans = 0.0;
    F(i, n/2+1, n+1) {
    	ans += dp[n][i];
    }
    coud(ans, 10);

    return 0;
}/*

*/
