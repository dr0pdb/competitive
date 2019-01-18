#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 5e5+5;
string s;
int arr[2][N]; // 0 - need left, 1 - needs right.

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    memset(arr, 0, sizeof(arr));

    int ans = 0;
    F(i, 0, n) {
    	cin>>s;
    	stack<char> st;
    	bool needl = false, needr = false; int lcnt=0, rcnt=0;
    	F(j, 0, s.size()) {
    		if(s[j] == '(') {
    			st.push('(');
    			rcnt++;
    		} else {
    			if(!st.empty()) {
    				st.pop();
    				rcnt--;
    			} else {
    				needl = true;
    				lcnt++;
    			}
    		}
    	}

    	if(rcnt)
    		needr = true;

    	if(!needr && !needl) {
    		ans++;
    		continue;
    	}

    	if(rcnt && lcnt) {
    		continue;
    	}

   		if(rcnt) {
   			arr[1][rcnt]++;
   		} else {
   			arr[0][lcnt]++;
   		}
    }

    ans/=2;
    F(i, 1, N) {
    	ans += min(arr[0][i], arr[1][i]);
    }
    cout<<ans;

    return 0;
}/*

*/
