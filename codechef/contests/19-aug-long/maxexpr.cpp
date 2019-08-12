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

const int N = 1e5+5;
double k[N],c[N], vals[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n; cin>>t;
    while(t--) {
    	cin>>n; double sumk = 0;
    	FOR(i, 0, n) {
    		cin>>k[i];
    		sumk += 1.0/k[i];
    	}
    	FOR(i, 0, n) cin>>c[i];
    	double res = 0;
    	FOR(i, 0, n) {
    		res += c[i] * k[i];
    	}
    	if (res < 0)
    	{
    		cout<<-1<<endl;
    		continue;
    	}
    	// deb(res); deb(sumk);
    	double a = res / sumk, ans = 0;
    	FOR(i, 0, n) {
    		vals[i] = (a / k[i] / k[i]) - c[i];
    		ans += sqrt(a / k[i] / k[i]);
    	}
    	coud(ans, 10)
    	FOR(i, 0, n) {
    		cout<<" "; coud(vals[i], 10)
    	}
    	cout<<endl;
    }

    return 0;
}