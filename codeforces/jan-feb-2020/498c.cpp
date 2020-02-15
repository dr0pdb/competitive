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
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int nax = 101;
int arr[nax], a[nax], b[nax];

template <class T = int>
class Dinic
{
public:
	struct Edge
	{
		Edge(int a, T b)
		{
			to = a;
			cap = b;
		}
		int to;
		T cap;
	};

	Dinic(int n)
	{
		edges.resize(n);
		this->n = n;
	}

	T maxFlow(int src, int sink)
	{
		T ans = 0;
		while (bfs(src, sink))
		{
			T flow;
			pt = std::vector<int>(n, 0);
			while ((flow = dfs(src, sink)))
			{
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap = 1)
	{
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0));
	}

private:
	int n;
	std::vector<std::vector<int>> edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow = INF)
	{
		if (flow == 0)
		{
			return 0;
		}
		if (on == sink)
		{
			return flow;
		}
		for (; pt[on] < edges[on].size(); pt[on]++)
		{
			int cur = edges[on][pt[on]];
			if (h[on] + 1 != h[list[cur].to])
			{
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if (got)
			{
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink)
	{
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while (!q.empty())
		{
			int on = q.front();
			q.pop();
			for (auto a : edges[on])
			{
				if (list[a].cap == 0)
				{
					continue;
				}
				int to = list[a].to;
				if (h[to] > h[on] + 1)
				{
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
	set<int> pp;
    int n,m; cin>>n>>m;
    FOR(i, 0, n) {
        cin>>arr[i]; int tmp = arr[i];
		FOR(j, 2, sqrt(arr[i]) + 2) {
			bool done = false;
			while(tmp > 0 && tmp % j == 0) {
				tmp /= j;
				if(!done) {
					pp.insert(j);
					done = true;
				}
			}
			if(tmp == 0) break;
		}
		if(tmp > 1) pp.insert(tmp); // if tmp is prime.
	}
	FOR(i, 0, m) {
		cin>>a[i]>>b[i]; a[i]--; b[i]--;
		if(a[i] % 2 != 0) {
			swap(a[i], b[i]);
		}
	}
	int res = 0;
	for(int p : pp) {
		Dinic<int> graph(n + 2); // n : src and n + 1 : sink
		int src = n, sink = n + 1;

		// add edges from src,sink to vertices
		FOR(i, 0, n) {
			int cnt = 0, tmp = arr[i];
			while(tmp > 0 && tmp%p == 0) {
				cnt++;
				tmp /= p;
			}
			if(i % 2 == 0) {
				graph.addEdge(src, i, cnt);
			} else {
				graph.addEdge(i, sink, cnt);
			}
		}

		// add middle edges
		FOR(i, 0, m) {
			graph.addEdge(a[i], b[i], 100); // setting capacity to 100 works because the bottleneck will be the edges b/w src,sink and vertices.
		}

		res += graph.maxFlow(src, sink);
	}
	cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}