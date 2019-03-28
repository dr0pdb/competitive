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

string s;
const int N = 5e6+5;
const int p = 31;
const int m = 1e9 + 9;
ll p_pow[N],h[N];

void compute_hash(string const& s) {
    for (int i = 0; i < s.size(); i++) {
        h[i] = (((i) ? h[i-1] : 0) + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
}

void compute_p_pow() {
	p_pow[0]=p;
	FOR(i, 1, N) {
		p_pow[i] = (p_pow[i-1] * p) % m;
	}
}

bool check(int mid, int p) {
	long long h1 = (h[mid-1]*p_pow[p-1])%m;
	long long h2 = (h[p + mid - 1]-h[p-1] + m)%m;
	return h1 == h2;
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	compute_p_pow();
	getline(cin, s);
	// deb(s);

	int n = s.size();
	compute_hash(s);

	int q,p;
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &p);

		int len1 = p;
		int len2 = n - p;
		int lo = 1, hi = min(len1, len2),ans=0;
		while(lo <= hi) {
			int mid = (lo + hi)/2;
			if(check(mid, p)) {
				ans = max(ans, mid);
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		printf("%d", ans);
		if(q) printf("\n");
	}

 	
    return 0;
}