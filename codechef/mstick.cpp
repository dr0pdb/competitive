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
int st[MAXN][K], st2[MAXN][K];
int logg[MAXN+1];

void pre(int array[]) {
	logg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
    	logg[i] = logg[i/2] + 1;

    for (int i = 0; i < N; i++) {
    	st[i][0] = array[i];
    	st2[i][0] = array[i];
    }

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st2[i][j] = max(st2[i][j-1], st2[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
	int j = logg[R - L + 1];
	return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int query2(int L, int R) {
	int j = logg[R - L + 1];
	return max(st2[L][j], st2[R - (1 << j) + 1][j]);
}

int arr[MAXN];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>N;
    FOR(i, 0, N) {
    	cin>>arr[i];
    }
    pre(arr);
    int q,l,r; cin>>q;
    while(q--) {
    	cin>>l>>r;
    	int minm = query(l, r);
    	int maxm = 0, maxm2 = 0,maxm3 = 0;
    	if(l - 1 >= 0) {
    		maxm = query2(0, l-1);
    	}
    	if (r + 1 < N)
    	{
    		maxm2 = query2(r+1, N-1);
    	}
    	if (r - l + 1 > 1)
    	{
			maxm3 = query2(l, r);
    	}
    	maxm3 -= minm; maxm3 = max(0, maxm3);
    	// cout<<maxm<<" "<<maxm2<<" "<<maxm3<<endl;
    	double ans = minm + 1.0 * max(2 * maxm, max(2 * maxm2, maxm3)) / 2;
    	coud(ans, 1); cout<<endl;
    }

    return 0;
}