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

int n,m,x,y; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer, maxval=-1;
bool poss = true;
set<ii> edges, answer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    maxval = v;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
            if(to != p && edges.find({min(to,v), max(to,v)})!= edges.end()) {
            	answer.insert({v, to});
            	edges.erase({min(to,v), max(to,v)});
            }
        } else {
        	answer.insert({v, to});
        	edges.erase({min(to,v), max(to,v)});
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                poss = false;
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    adj.resize(n);
    FOR(i, 0, m) {
    	cin>>x>>y;
    	x--; y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    	edges.insert({min(x,y), max(x,y)});
    }
    find_bridges();
    if(!poss) {
    	cout<<0;
    	return 0;
    }
    for(auto edge: answer) {
    	cout<<edge.ff+1<<" "<<edge.ss+1<<endl;
    }
    for(auto edge: edges) {
    	cout<<edge.ff+1<<" "<<edge.ss+1<<endl;
    }

    return 0;
}