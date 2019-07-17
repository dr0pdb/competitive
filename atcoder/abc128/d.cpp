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

const int N = 51;
int v[N], dp[51][51],n,k,ks;

int solve(int aa, int bb, vi &hand, int sum) {
	if(aa + bb == ks) {
		int left = k - aa - bb; vi negs;
		FOR(i, 0, hand.size()) {
			if(hand[i] < 0) negs.push_back(hand[i]);
		}
		sort(negs.begin(), negs.end());
		int sm2 = 0;
		FOR(i, 0, min(left, (int)negs.size())) {
			sm2 += negs[i];
		}
		return max(sum, sum - sm2);
	}
	int &ret = dp[aa][bb];
	if(ret >= 0) return ret;
	
	hand.push_back(v[aa]); sum += v[aa];
	ret = max(ret, solve(aa+1, bb, hand, sum));
	hand.pop_back(); sum -= v[aa];

	hand.push_back(v[n-1-bb]); sum += v[n-1-bb];
	ret = max(ret, solve(aa, bb+1, hand, sum));
	hand.pop_back(); sum -= v[n-1-bb];
	
	int left = k - aa - bb; vi negs;
	FOR(i, 0, hand.size()) {
		if(hand[i] < 0) negs.push_back(hand[i]);
	}
	sort(negs.begin(), negs.end());
	int sm2 = 0;
	FOR(i, 0, min(left, (int)negs.size())) {
		sm2 += negs[i];
	}
	ret = max(ret, sum - sm2);
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>k; ks = min(k, n);
    FOR(i, 0, n) cin>>v[i];
    memset(dp, -1, sizeof(dp));
    vi hand;
   	cout<<solve(0,0,hand,0);
    return 0;
}