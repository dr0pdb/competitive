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

/*
    The idea is to create another graph. Nodes of this graph are the edges
    of the original graph.
    There won't be an edge from (1, 2) and (2, 4) if (1, 2, 4) is invalid.
    Do a bfs on this new graph from all the nodes which are (1, *) to all the nodes which are (*, n)
*/

const int N = 3005;
vi g[N];
int n,m,k,x,y,z;
set<pair<ii,int>> invalid;
vector<ii> ee;
int parent[40005],dist[40005];
bool visited[40005];

void printpath(int curr) {
	if (curr == -1)	return;
	printpath(parent[curr]);
    if (parent[curr] == -1)
    {
        cout<<ee[curr].ff<<" ";
    }
	cout<<ee[curr].ss<<" ";
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    FOR(i, 0, m) {
    	cin>>x>>y;
        ee.push_back({x, y});
    	g[x].push_back(2*i); // index into the edge list.
    	ee.push_back({y, x});
        g[y].push_back(2*i+1);
        dist[i] = INF;
    }
    FOR(i, 0, k) {
        cin>>x>>y>>z;
        invalid.insert({{x,y}, z});
    }
    memset(visited, false, sizeof(visited));
    queue<int> q; memset(parent, -1, sizeof(parent));
    int minm_idx = -1, minm = INF;
    for(auto itr : g[1]) {
        q.push(itr);
        visited[itr] = true;
        dist[itr] = 1;
        if (ee[itr].ss == n)
        {
            cout<<1<<endl;
            cout<<1<<" "<<n<<endl;
            return 0;
        }
    }
    while(!q.empty()) {
        int idx = q.front(); q.pop();
        tie(x, y) = ee[idx];

        for(int idx2 : g[y]) {
            assert(ee[idx2].ff == y);
            int z = ee[idx2].ss;
            if (invalid.find({{x, y}, z}) != invalid.end()) continue;
            if (!visited[idx2])
            {
                visited[idx2] = true;
                parent[idx2] = idx;
                q.push(idx2);
                dist[idx2] = dist[idx] + 1;
                if (z == n && minm > dist[idx2])
                {
                    minm_idx = idx2;
                    minm = dist[idx2];
                }
            }
        }
    }
    if (minm_idx == -1)
    {
        cout<<-1;
        return 0;
    }
    cout<<dist[minm_idx]<<endl;
    printpath(minm_idx);
    return 0;
}