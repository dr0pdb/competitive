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

const int K=1e5+5;
int dp[K], a[105]; // 0 - losing pos, 1 - winning pos

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    memset(dp, 0, sizeof(dp));
    F(i, 0, n) {
    	cin>>a[i];
    }

    F(i, 1, k+1) {
    	bool found = false;
    	F(j, 0, n) {
    		if(i < a[j]) continue;
    		found |= (dp[i - a[j]] == 0);
    	}

    	if(found) dp[i]=1;
    	else dp[i]=0;
    }

    if(dp[k]) {
    	cout<<"First";
    } else {
    	cout<<"Second";
    }


    return 0;
}/*

*/
