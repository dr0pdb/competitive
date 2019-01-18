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

const int N = 1e3+5;
ll dp[N][N];
char mat[N][N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int h,w;
    cin>>h>>w;

    F(i, 0, h) {
    	F(j, 0, w) {
    		cin>>mat[i][j];
    	}
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    F(i, 0, h) {
    	F(j, 0, w) {
    		if((i+j) == 0 || mat[i][j] == '#') continue;
    		if(i) {
    			dp[i][j] += dp[i-1][j];
    			dp[i][j] %= MOD;
    		}
    		if(j) {
    			dp[i][j] += dp[i][j-1];
    			dp[i][j] %= MOD;
    		}
    	}
    }
    cout<<dp[h-1][w-1];

    return 0;
}/*

*/