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
vi g[N];
int p[N],c[N];
vi deletables;

int dfs(int curr, int par = -1) {
	int respect = 0;
	for(auto next: g[curr]) {
		if(next != par) {
			respect += dfs(next);
		}
	}
	if(c[curr]==0 && respect == 0) {
		deletables.push_back(curr+1);
	}

	return c[curr];
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,root;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>p[i]>>c[i];
    	c[i] = 1 - c[i];
    	if(p[i] == -1) {
    		root = i;
    		continue;
    	}
    	p[i]--;
    	g[p[i]].push_back(i);
    }

    dfs(root);
    if (deletables.size())
    {
    	sort(deletables.begin(), deletables.end());
    	for(auto num: deletables) {
    		cout<<num<<" ";
    	}
    } else {
    	cout<<-1;
    }

    return 0;
}