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

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    string s;
    cin>>s;

    vii golds;
    int start=-1, end = -1,cnt=0;
    F(i, 0, n) {
    	if(s[i] == 'G') {
    		cnt++;
    		end=i;
    		if(start == -1) {
    			start = i;
    		}
    	} else {
    		if(start != -1) {
				golds.push_back({start, end});
    		}
    		start = -1;
    		end = -1;
    	}
    }

    if(start != -1) {
    	golds.push_back({start, end});
    }

    int ans = 0;

    F(i, 0, golds.size()) {
    	if(cnt > golds[i].second - golds[i].first + 1) {
    		ans = max(ans, golds[i].second - golds[i].first + 2);
    	} else {
    		ans = max(ans, golds[i].second - golds[i].first + 1);	
    	}
    }

    if(golds.size() > 1) {
    	F(i, 0, golds.size()-1) {
    		int fend = golds[i].second;
    		int sstart = golds[i+1].first;
    		if(sstart - fend == 2) {
    			if(cnt > (fend + 1 - golds[i].first) + (golds[i+1].second - sstart + 1)) {
    				ans = max(ans, 1 + (fend + 1 - golds[i].first) + (golds[i+1].second - sstart + 1));
    			} else {
    				ans = max(ans, (fend + 1 - golds[i].first) + (golds[i+1].second - sstart + 1)); 
    			}
    		}
    	}
    }

    cout<<ans;
    return 0;
}/*

*/
