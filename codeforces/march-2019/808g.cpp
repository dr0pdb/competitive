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

string T,P;
vector<vi> dp;
#define MAX_N 100010
int b[MAX_N], n, m; // n = size of text, m = size of pattern.
int next_hop[26][MAX_N];

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;

	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	} 
}

void buildNextHop() {
	memset(next_hop, 0, sizeof(next_hop));
	FOR(i, 0, 26) {
		FOR(j, 0, m) {
			int tmpj = j;
			while(tmpj >= 0 && ((char)'a' + i) != P[tmpj]) tmpj = b[tmpj];
			tmpj++;
			next_hop[i][j] = tmpj;
		}
	}
}

int solve(int i, int j) {
	if (i == n)
		return 0;
	int &ret = dp[i][j];
	if(ret >= 0) return ret;
	ret = 0;
	int tmpj=j;

	if(T[i] != '?') {
		while(tmpj >= 0 && T[i] != P[tmpj]) tmpj = b[tmpj];
		tmpj++;
		if(tmpj == m) {
			ret = max(ret, 1 + solve(i+1, b[tmpj]));
		} else {
			ret = max(ret, solve(i+1, tmpj));
		}
		return ret;
	}

	// when we make ? equal to P[j]
	tmpj = j + 1;
	if(tmpj == m) {
		ret = max(ret, 1 + solve(i + 1, b[tmpj]));
	} else {
		ret = max(ret, solve(i + 1, tmpj));
	}

	// when we make it other than P[j]
	for (char c = 'a'; c <= 'z'; ++c)
	{
		if(P[j] == c) continue;
		tmpj = next_hop[c-'a'][j];
		if(tmpj == m) {
			ret = max(ret, 1 + solve(i+1, b[tmpj]));
		} else {
			ret = max(ret, solve(i+1, tmpj));
		}
	}

	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>T>>P;
    n = T.size(); m = P.size();
    if(n < m) {
    	cout<<0;
    	return 0;
    }
    kmpPreprocess();
    buildNextHop();
    dp.resize(n+1, vi(m+1, -1));
    cout<<solve(0, 0);

    return 0;
}