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

int freq[10];
ll fact[20];
ll ans;

void solve(int num, vi curr) {
	if(num == 10) {
		ll sum = 0;
		F(i, 0, 10) {
			sum += curr[i];
		}
		ll ret = 0;
		ret = fact[sum];
		F(i, 0, 10) {
			ret /= fact[curr[i]];
		}

		ll sub = 0;
		if(curr[0]) {
			sub = fact[sum-1];
			F(i, 1, 10) {
				sub /= fact[curr[i]];
			}
			sub /= fact[curr[0]-1];
		}
		
		ans += ret - sub;
		return;
	}

	if(freq[num]) {
		F(i, 1, freq[num]+1) {
			curr[num]=i;
			solve(num+1, curr);
		}
	} else {
		solve(num+1, curr);
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    fact[0]=1;
    F(i, 1, 20) {
    	fact[i]= i*fact[i-1];
    }

    ll n;
    cin>>n;

    string num;
    num = to_string(n);
    memset(freq, 0, sizeof(freq));

    F(i, 0, num.size()) {
    	freq[num[i]-'0']++;
    }
    ans = 0;
    vi curr(10, 0);
    solve(0, curr);
    cout<<ans;

    return 0;
}/*

*/
