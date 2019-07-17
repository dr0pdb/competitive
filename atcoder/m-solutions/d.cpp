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

const int N = 10001;
vii edges;
int c[N], label[N], ans=0;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    memset(label, -1, sizeof(label));
    cin>>n; edges.resize(n-1);
    FOR(i, 0, n-1) {
    	cin>>edges[i].ff >> edges[i].ss;
    	edges[i].ff--; edges[i].ss--;
    }
    FOR(i, 0, n) cin>>c[i];
    sort(c, c+n, greater<int>());
    label[edges[0].ff]=c[0]; label[edges[0].ss]=c[1];
    FOR(i, 2, n) {
    	ans += c[i];
    	int curr = -1;
    	FOR(j, 0, n-1) {
    		if(label[edges[j].ff] != -1 ^ label[edges[j].ss] != -1) {
    			curr = edges[j].ff;
    			if(label[curr] != -1) curr = edges[j].ss;
    			break;
    		}
    	}
    	label[curr]=c[i];
    }
    ans += c[1];
    cout<<ans<<endl;
    FOR(i, 0, n) {
    	cout<<label[i]<<" ";
    }
    return 0;
}