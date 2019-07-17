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

const int N = 1e6+1;
int nextone[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int k,n,last; cin>>k; string s; cin>>s;
	ll ans = 0; n = s.size(); last=n;
	if(!k) {
		int j = 0,cnt=0;
		FOR(i, 0, n) {
			j = max(j, (int)i);
			while(j < n && s[j]=='0') {
				j++;
			}
			ans += (j - i) * 1LL * (j - i + 1) / 2;
			i = j;
		}
		cout<<ans;
		return 0;
	}
	RFOR(i, n-1, 0) {
		nextone[i] = last;
		if(s[i] == '1') {
			last = i;
		}
	}
	int j=0, cnt = 0;
	FOR(i, 0, n) {
		while(j < n && cnt < k) {
			if(s[j] == '1') cnt++;
			j++;
		}
		if(cnt == k) {
			j--;
			ans += (nextone[j] - j);
			j++;
		}
		if(s[i] == '1') {
			cnt--;
		}
	}
	cout<<ans;

    return 0;
}