#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

class EllysCodeConstants {
  public:
  	int n;
  	map<char,char> rep = {{'O', '0'}, {'I', '1'}, {'Z', '2'}, {'S', '5'}, {'T', '7'}};
  	set<char> sufchars = {'L', 'U'};
  	set<string> threes = {"LLU", "ULL"};
  	set<string> twos = {"LL", "UL", "LU"};
  	set<string> ones = {"L", "U"};

  	bool valid(char c) {
  		return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'));
  	}

  	int suffix_start(string &s) {
  		string suff = "";
  		RFOR(i, n-1, max(0, n-3)) {
  			if(sufchars.find(s[i]) == sufchars.end()) {
  				break;
  			}
  			suff.push_back(s[i]);
  		}
  		if(suff.empty()) return n;
  		reverse(suff.begin(), suff.end());
  		if(threes.find(suff) != threes.end()) return n - 3;
  		if(suff.size() == 3) suff.erase(0, 1);
		if(twos.find(suff) != twos.end()) return n - 2;
  		if(suff.size() == 2) suff.erase(0, 1);
  		if(ones.find(suff) != ones.end()) return n - 1;
		if(suff.size() && ((suff[0] >= '0' && suff[0] <= '9') || (suff[0] >= 'A' && suff[0] <= 'F'))) return n;
  		return -1;
  	}

	string getLiteral(string candidate) {
		n = candidate.size();
		string ret = "";

		FOR(i, 0, n) {
			if(rep.find(candidate[i]) != rep.end()) {
				candidate[i] = rep[candidate[i]];
			}
		}
		int suff_idx = suffix_start(candidate);
		if(suff_idx == -1) return ret;
		FOR(i, 0, suff_idx) {
			if(!valid(candidate[i])) {
				ret.clear();
				return ret;
			}
			ret.push_back(candidate[i]);
		}
		FOR(i, suff_idx, n) {
			ret.push_back(candidate[i]);
		}

		ret.insert(0, sizeof(char), 'x');
		ret.insert(0, sizeof(char), '0');

		return ret;
	}
};