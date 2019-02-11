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
const ll MOD = 998244353;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 1001;
ll dp[N][2*N][4];

bool full(int mask){
	return (mask == 0 || mask == 3);
}

int get(int prevmask, int mask) {
	int cnt = __builtin_popcount(prevmask ^ mask);
	if (cnt == 0) return 0;
	if (cnt == 2) return (full(prevmask) ? 1 : 2);
	return (full(mask) ? 0 : 1);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	// for (int i = 0; i <= 3; ++i)
	// {
	// 	for (int j = 0; j <= 3; ++j)
	// 	{
	// 		printf("%d %d - %d\n", i, j, get(i, j));
	// 	}
	// }


    memset(dp, 0, sizeof(dp));
    int n,kx;
    cin>>n>>kx;

    dp[1][1][0]=1;dp[1][2][1]=1;dp[1][2][2]=1;dp[1][1][3]=1;

    F(i, 2, n+1) {
    	F(j, 1, kx+1) {
    		F(mask, 0, 4) {
    			F(prevmask, 0, 4) {
    				int diff = get(prevmask, mask);
    				if(diff <= j) {
    					dp[i][j][mask] += dp[i-1][j-diff][prevmask];
    					dp[i][j][mask] %= MOD;
    				}
    			}
    		}
    	}
    }

    // F(i, 1, n+1) {
    // 	F(j, 1, kx+1) {
    // 		F(k, 0, 4) {
    // 			cout<<dp[i][j][k]<<" ";
    // 		}
    // 	}
    // 	cout<<endl;
    // }

    ll ans = 0;
    F(i, 0, 4) {
    	ans += dp[n][kx][i];
    	ans %= MOD;
    }
    cout<<ans;


    return 0;
}/*

*/