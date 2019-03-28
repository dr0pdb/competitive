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

ll dp[40][40],par[40][40];
ll power10[19];
int n;
vector<int> v;

ll solve(int a, int b) {
	if(a == n && b == n) return 0;
	ll &ret = dp[a][b];
	if(ret >= 0) return ret;

	ret = -1;
	if(a < n) {
		ret = (power10[n - a])*v[a + b] + solve(a+1, b);
		par[a][b]=0;
	}

	if(b < n) {
		ll val = power10[n - b]*v[a + b] + solve(a, b+1);
		if(val > ret) {
			ret = val;
			par[a][b]=1;
		}		
	}

	return ret;
}

void printSol(int a, int b) {
	if(a == n && b == n) return;
	if(par[a][b] == 1) {
		cout<<'M';
		printSol(a, b+1);
	} else if(par[a][b] == 0){
		cout<<'H';
		printSol(a+1, b);
	}
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tmp;
    cin>>n;
    power10[0]=1;
    FOR(i, 1, 19) {
    	power10[i] = 10 * power10[i-1];
    }

    FOR(i, 0, 2*n) {
    	scanf("%1d", &tmp);
    	v.push_back(tmp);
    }

    memset(par, -1, sizeof(par));
    memset(dp, -1, sizeof(dp));
    solve(0, 0);
    printSol(0,0);

    return 0;
}