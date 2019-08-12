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

class WildSequence {
public:
	vector <int> construct(int, vector <int>);
};

vector <int> WildSequence::construct(int head, vector <int> rest) {
	vi ret = {head};
	int n = rest.size(), curr = 0, turn=0, l = 0, r = n - 1;
	bool done = true;
	sort(rest.begin(), rest.end());
	while(ret.size() <= n) {
		if(turn) {
			if(ret.back() < rest[r]) curr--;
			else curr++;
			ret.push_back(rest[r]); r--;
		} else {
			if(ret.back() < rest[l]) curr--;
			else curr++;
			ret.push_back(rest[l]);
			l++;
		}
		if(abs(curr) > 1) {
			done = false;
			break;
		}
		turn = 1 - turn;
	}
	if(done) return ret;
	ret.clear(); ret.push_back(head);
	l = 0, r = n - 1, curr = 0, turn = 1; done = true;
	while(ret.size() <= n) {
		if(turn) {
			if(ret.back() < rest[r]) curr--;
			else curr++;
			ret.push_back(rest[r]); r--;
		} else {
			if(ret.back() < rest[l]) curr--;
			else curr++;
			ret.push_back(rest[l]);
			l++;
		}
		if(abs(curr) > 1) {
			done = false;
			break;
		}
		turn = 1 - turn;
	}
	if(!done) ret.clear();
	return ret;
}


//Powered by [KawigiEdit] 2.0!
