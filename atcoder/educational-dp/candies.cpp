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

const int N = 105, K = 1e5+5;
ll dp[N][K],arr[N],cum[N][K];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    memset(dp, 0, sizeof(dp));
    memset(cum, 0, sizeof(cum));
    int n,k;
    cin>>n>>k;

    F(i, 0, n) {
    	cin>>arr[i];
    }

    F(j, 0, k+1) {
        if(j <= arr[0]) {
            dp[1][j]=1;
            cum[1][j]=1;
        }

        if(j) cum[1][j] += cum[1][j-1];
        cum[1][j] %= MOD;
    }

    F(i, 2, n+1) {
    	F(j, 0, k+1) {
    		dp[i][j] = cum[i-1][j];
            if(j - arr[i-1] > 0) {
                dp[i][j] -= cum[i-1][j-arr[i-1]-1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
            cum[i][j] = dp[i][j];
            if(j) cum[i][j] += cum[i][j-1];
            cum[i][j] %= MOD;
    	}
    }
    cout<<dp[n][k];

    return 0;
}/*

*/
