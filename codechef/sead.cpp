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

const int MAXN = 1e5+1;
const int K = 25;
int N;
int st[MAXN][K], logg[MAXN+1], arr[MAXN], diff[MAXN];

void pre(int array[]) {
	logg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
    	logg[i] = logg[i/2] + 1;

    for (int i = 0; i < N; i++)
    	st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
	int j = logg[R - L + 1];
	return max(st[L][j], st[R - (1 << j) + 1][j]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,t,d; cin>>n; N = n;
    FOR(i, 0, n) {
    	cin>>arr[i];
    	if (i)
    	{
    		diff[i-1] = arr[i] - arr[i-1];
    	}
    }
    N--;
    pre(diff);
    cin>>m;
    FOR(i, 0, m) {
    	cin>>t>>d;
    	int k = upper_bound(arr, arr+n, t) - arr;
    	k--;
    	// deb(k);
    	int lo = 0, hi = k - 1, ans = k;
    	while(lo <= hi) {
    		int mid = (lo + hi)/2;
    		int res = query(mid, hi);
    		if (res > d)
    		{
    			lo = mid + 1;
    		} else {
    			ans = min(ans, mid);
    			hi = mid - 1;
    		}
    	}
    	cout<<ans+1<<endl;
    }

    return 0;
}