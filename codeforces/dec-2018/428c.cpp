#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
vi g[N];
bool visited[N];

double solve(int curr) {
	double ret = 0.0;
	visited[curr] = true;

	int cnt = 0;
	F(i, 0, g[curr].size()) {
		int next = g[curr][i];
		if(!visited[next]) {
			cnt++;
			ret += (1.0 + solve(next));
		}
	}

	if(cnt) {
		ret /= (double)cnt;
	}

	return ret;
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n,u,v;
    cin>>n;

    F(i, 0, n-1) {
    	scanf("%d %d", &u, &v);
    	u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    printf("%.12f", solve(0));

    return 0;
}/*

*/
