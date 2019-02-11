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

bool compareWithSuffix(string &a, string &suff) {
	int sz1 = a.size(), sz2 = suff.size();
	int ind1 = sz1-1, ind2 = sz2-1;
	while(ind1 >= 0) {
		if(a[ind1] != suff[ind2]) {
			return false;
		}

		ind1--; ind2--;
	}

	return true;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    string subs[205];
    char ans[205];
    map<int, vi> m;
    vi l;
    F(i, 0, 2*n-2) {
    	cin>>subs[i];
    	if(subs[i].size() == n-1) {
    		l.push_back(i);
    	}
    	m[subs[i].size()].push_back(i);
    }
    // deb(n);

	F(i, 0, l.size()) {
		memset(ans, '0', sizeof(ans));
		int pref = l[i], suff = l[1-i];
		ans[pref]='P'; ans[suff]='S';
		bool valid = true;

		for(auto itr = m.begin(); itr != m.end(); ++itr) {
			int sz = itr->first;
			if(sz == n-1) {
				continue;
			}
			vi vals = itr -> second;
			if(subs[vals[0]] == subs[pref].substr(0, sz)) {
				ans[vals[0]]='P';
				ans[vals[1]]='S';
			} else if(compareWithSuffix(subs[vals[0]], subs[suff])) {
				ans[vals[0]]='S';
				ans[vals[1]]='P';
			} else {
				valid = false;
				break;
			}
		}

		if(valid) {
			break;
		}
	}

	F(i, 0, 2*n-2) {
		cout<<ans[i];
	}


    return 0;
}/*

*/
