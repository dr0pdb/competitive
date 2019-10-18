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
const ll INF = 1e11+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 1001;
int arr[N],p[N];
vll cols[N];
int t,n,k;
ll dp[N][N];

ll solve(int idx, int ks) {
	if(idx == N || !ks) {
		if(ks) return INF;
		return 0;
	}
	ll &ret = dp[idx][ks];
	if(ret >= 0) return ret;
	ret = INF;
	ret = min(ret, solve(idx+1, ks));
	int sz = min((int)cols[idx].size(), ks) + 1;
	FOR(i, 1, sz) {
		if(ks == i) {
			ret = min(ret, cols[idx][i-1]);
			break;	
		}
		ret = min(ret, 2*cols[idx][i-1] + solve(idx+1, ks - i));
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>t;
    FOR(tn, 1, t+1) {
		cin>>n>>k;
		memset(dp, -1, sizeof(dp));
		FOR(i, 0, N) cols[i].clear();
		FOR(i, 0, n) cin>>p[i];
		FOR(i, 0, n) cin>>arr[i];
		FOR(i, 0, n) {
			cols[arr[i]].push_back(p[i]);
		}
		sort(cols+1, cols+N);
		FOR(i, 1, N) {
			sort(cols[i].begin(), cols[i].end());
			if(!cols[i].size()) continue; 
			FOR(j, 1, cols[i].size()) {
				cols[i][j] += cols[i][j-1];
			}
		}
		ll ans = solve(1, k);
    	cout<<"Case #"<<tn<<": "<<ans<<endl;
    }

    return 0;
}