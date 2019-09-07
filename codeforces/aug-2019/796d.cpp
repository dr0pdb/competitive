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

const int N = 3e5+5;
int n,k,d,p,u,v;
bool visited[N];
bool del[N];
vii g[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>k>>d;
    queue<ii> q;
	memset(visited, false, sizeof(visited));
    FOR(i, 0, k) {
    	cin>>p;
    	q.push({p, 0});
    }
    FOR(i, 0, n-1) {
    	cin>>u>>v;
    	g[u].push_back({v, i + 1});
    	g[v].push_back({u, i + 1});
    }
    memset(del, false, sizeof(del));
    while(!q.empty()) {
    	int curr, par;
    	tie(curr, par) = q.front(); q.pop();
    	if (visited[curr])
    	{
    		continue;
    	}
    	visited[curr] = true;
    	for(auto idx : g[curr]) {
    		int nxt = idx.ff; 
    		if (nxt == par) continue;
    		if (visited[nxt])
    		{
    			del[idx.ss] = true;	
    		} else if(!visited[nxt]) {
    			q.push({nxt, curr});
    		}
    	}
    }
    int cnt = 0;
    FOR(i, 1, n) cnt += (del[i]);
    cout<<cnt<<endl;
    FOR(i, 1, n) {
    	if(del[i]) {
    		cout<<i<<" ";
    	}
    }
    return 0;
}