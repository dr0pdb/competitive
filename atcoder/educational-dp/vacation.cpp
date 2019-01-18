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

const int N = 1e5+5;
int dp[N][3],vals[N][3];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    F(i, 0, n) {
    	F(j, 0, 3) {
    		cin>>vals[i][j];
    	}
    }
    memset(dp, -1, sizeof(dp));
    F(i, 0, 3) {
    	dp[0][i]=vals[0][i];
    }

    F(i, 1, n) {
    	F(j, 0, 3) {
    		int maxm = -1;
    		F(k, 0, 3) {
    			if(k == j) continue;
    			maxm = max(maxm, dp[i-1][k]);
    		}
    		dp[i][j]= maxm + vals[i][j];
    	}
    }
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

    return 0;
}/*

*/
