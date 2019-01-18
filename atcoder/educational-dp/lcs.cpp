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
int dp[N][N],par[N][N]; // 0 - i-1,j. 1 - i,j-1 and 2 - i-1,j-1.
string s,t;

void solve(int sx, int tx, string &ans) {
	if(sx<=0 || tx<=0) return;
	switch(par[sx][tx]) {
		case 0:
			solve(sx-1, tx, ans);
			break;
		case 1:
			solve(sx, tx-1, ans);
			break;
		case 2:
			solve(sx-1, tx-1, ans);
			ans.push_back(s[sx-1]);
			break;
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>s>>t;

    int sz[2];
    sz[0]=s.size(); sz[1]=t.size();
    memset(dp, -1, sizeof(dp)); memset(par, -1, sizeof(par));
    dp[0][0]=0;
    F(i, 1, sz[0]+1) {
    	dp[i][0]=0;
    }

    F(i, 1, sz[1]+1) {
    	dp[0][i]=0;
    }

    F(i, 1, sz[0]+1) {
    	F(j, 1, sz[1]+1) {
    		par[i][j]=0;
    		if(dp[i][j-1]>dp[i-1][j]) par[i][j]=1;
    		dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    		if(s[i-1] == t[j-1]) {
    			if(1+dp[i-1][j-1]>dp[i][j]) par[i][j]=2;
    			dp[i][j]=max(dp[i][j], 1+dp[i-1][j-1]);
    		}
    	}
    }
    string ans="";
    solve(sz[0], sz[1], ans);
    cout<<ans;

    return 0;
}/*

*/
