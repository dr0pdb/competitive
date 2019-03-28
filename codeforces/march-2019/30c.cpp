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

const int N = 1005;
struct t
{
	int x,y,t;
	double p;
} target[N];
double dp[N];

bool cmp(t a, t b) {
	return a.t < b.t;
}

double sq(double a) {
	return a*a;
}

double dist(int i, int j) {
	return sqrt(sq(target[i].y - target[j].y) + sq(target[i].x - target[j].x));
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x,y,t;
    double p;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>x>>y>>t>>p;
    	target[i].x = x;
    	target[i].y = y;
    	target[i].t = t;
    	target[i].p = p;
    }

    sort(target, target+n, cmp);
    dp[0]=target[0].p;
    FOR(i, 1, n) {
    	dp[i] = target[i].p;
    	double maxm = 0.0;
    	FOR(j, 0, i) {
    		double timeleft = target[i].t - target[j].t;
    		double timetaken = dist(i, j);
    		if(timetaken > timeleft) continue;
    		maxm = fmax(maxm, dp[j]);
    	}
    	dp[i] += maxm;
    }
    coud(*max_element(dp, dp+n), 10);

    return 0;
}