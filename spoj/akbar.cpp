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

const int N = 1e6+5;
int n,m,r;
vi g[N];
int visiter[N];
ii guard[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,u,v;
    cin>>t;

    while(t--) {
    	cin>>n>>r>>m;
    	FOR(i, 0, n) g[i].clear();
    	FOR(i, 0, r) {
    		cin>>u>>v; u--; v--;
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	memset(visiter, -1, sizeof(visiter));
    	bool optimal = true;
    	queue<iii> q;
    	FOR(i, 0, m){
    		cin>>guard[i].ff>>guard[i].ss;
    		guard[i].ff--;
    		q.push({i, guard[i]});
    		if(visiter[guard[i].ff] == -1) {
    			visiter[guard[i].ff] = i;
    		} else {
    			optimal = false;
    		}
    	}
    	if(!optimal) {
    		cout<<"No\n";
    		continue;
    	}
    	while(!q.empty() && optimal) {
    		iii f = q.front(); q.pop();
    		int gno = f.ff;
    		int node = f.ss.ff;
    		int stamina = f.ss.ss;

    		if(!stamina) continue;
    		for(auto nxt : g[node]) {
    			if(visiter[nxt] != -1 && visiter[nxt] != gno) {
    				optimal = false;
    				break;
    			} else if(visiter[nxt] == -1) {
    				visiter[nxt] = gno;
    				q.push({gno, {nxt, stamina-1}});
    			}
    		}
    	}

    	FOR(i, 0, n) {
    		optimal &= (visiter[i] != -1);
    	}

    	if(optimal) {
    		cout<<"Yes\n";
    	} else {
    		cout<<"No\n";
    	}
    }

    return 0;
}