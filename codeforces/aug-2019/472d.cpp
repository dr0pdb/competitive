/**
    __author__ : srv_twry
**/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

int n;
const int N = 2001;
int dist[N][N];
bool done[N];
vector<vii> g;

void buildtree() {
	int cnt = n - 1;
	while(cnt) {
		int starter = 0;
		FOR(i, 0, n) {
			if(!done[i]) {
				starter = i;
				break;
			}
		}

		int maxd = -1, leaf = -1;
		FOR(j, 0, n) {
			if(!done[j] && j != starter) {
				if(dist[starter][j] > maxd) {
					maxd = dist[starter][j];
					leaf = j;
				}
			}
		}

		int mind = INF, neigh = -1;
		FOR(j, 0, n) {
			if(!done[j] && j != leaf) {
				if(dist[leaf][j] < mind) {
					mind = dist[leaf][j];
					neigh = j;
				}
			}
		}

		g[leaf].push_back({neigh, mind});
		g[neigh].push_back({leaf, mind});

		done[leaf] = true;
		cnt--;
	}
}

struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<ii>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vii> &adj, int node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto itr : adj[node]) {
        	int to = itr.ff; ll wt = itr.ss;
            if (!visited[to]) {
                dfs(adj, to, h + wt);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }

    ll dist(int u, int v) {
    	return height[u] + height[v] - 2 * height[lca(u, v)];
    }
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  	cin>>n; 
  	bool gone = false;
  	FOR(i, 0, n) {
  		FOR(j, 0, n) {
  			cin>>dist[i][j];
  			if(i != j && !dist[i][j]) {
				gone = true;
  			} else if(i == j) {
  				gone |= (dist[i][j] != 0);
  			}
  		}
  	}
  	if(gone) {
  		cout<<"NO";
  		return 0;
  	}
  	memset(done, false, sizeof(done));
  	g.resize(n);
  	buildtree();

  	// FOR(i, 0, n) {
  	// 	cout<<i<<" ";
  	// 	for(auto itr : g[i]) {
  	// 		cout<<itr.ff<<" ";
  	// 	}
  	// 	cout<<endl;
  	// }

  	LCA lc(g);
  	FOR(i, 0, n) {
  		FOR(j, 0, n) {
  			if(i == j) continue;
  			ll d = lc.dist(i, j);
  			if(d != dist[i][j]) {
  				cout<<"NO";
  				return 0;
  			}
  		}
  	}
  	cout<<"YES";
    return 0;
}