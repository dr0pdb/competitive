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

string a,b,ans="";
int sz;

void solve(int index, string &val, vi cnt) {
	if(index == sz) {
		ans = max(ans, val);
		return;
	}

	RF(i, 9, 0) {
		if(index == 0 && i == 0)
			continue;

		if(cnt[i]) {
			if(i == b[index]-'0') {
				val += b[index];
				cnt[i]--;
				solve(index+1, val, cnt);
				cnt[i]++;
				val.pop_back();
			} else if (i < b[index]-'0') {
				string tmp = val;
				tmp += (char)(i + '0');
				cnt[i]--;
				RF(j, 9, 0) {
					while(cnt[j]) {
						tmp += (char)(j + '0');
						cnt[j]--;
					}
				}
				ans = max(ans, tmp);
				break;
			}
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>a>>b;
    sz = a.size();
    int sz2 = b.size();
    if(sz2 > sz) {
    	sort(a.begin(), a.end(), greater<char>());
    	cout<<a;
    	return 0;
    }

    string val = "";
    vi cnt(10, 0);
    F(i, 0, sz) {
    	cnt[a[i]-'0']++;
    }
    solve(0, val, cnt);
    cout<<ans;

    return 0;
}/*

*/
