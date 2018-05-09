#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const ll INF = 1e9+10;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

const int FINDSIZE = 20005;
int p[FINDSIZE],sizes[FINDSIZE];

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y]){
			p[x] = y;
			sizes[y]+=sizes[x];
			
		}else{
			p[y] = x;
			sizes[x]+=sizes[y];
		}

	}
}

void initialiseUnionFind(){
	for(int i=0;i<FINDSIZE;i++){
		p[i] = i;
		sizes[i] = 1;
	}
}

const int N = 20005;
int n,m;
vii adjlist[N];
vector< pair<int, ii> > edgeList;
int mst;

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;

    while(t--){
    	initialiseUnionFind();
    	cin>>n>>m;
    	mst = 0;
    	F(i, 0, n){
    		adjlist[i].clear();
    	}
    	int a,b,w;
    	F(i, 0, m){
    		scanf("%d %d %d", &a, &b, &w);
    		edgeList.push_back(make_pair(w, ii(min(a, b), max(a,b))));
    		adjlist[a].push_back(ii(b, w));
    		adjlist[b].push_back(ii(a, w));
    	}

    	// kruskal

    	sort(edgeList.begin(), edgeList.end());
    	for (int i = 0; i < m; i++) {
			pair<int, ii> front = edgeList[i];
			if (!isSameSet(front.second.first, front.second.second)) {
				join(front.second.first, front.second.second);
				mst += edgeList[i].first;
			} 
		}

		// dijkstra
		vi dist(n,INF);
		vi parent(n, -1);
		dist[0] = 0;
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		pq.push(make_pair(0,ii(0,0)));
		vi lastvisited(n, INF);

		while(!pq.empty()) {
			iii front = pq.top(); pq.pop(); 
			int d = front.first, u = front.second.second;
			if (d > dist[u]) continue;

			for (int j = 0; j < (int)adjlist[u].size(); j++) {
				ii v = adjlist[u][j];
				if (dist[u] + v.second < dist[v.first] || (dist[u] + v.second == dist[v.first] && v.second < lastvisited[v.first])) {
					dist[v.first] = dist[u] + v.second;
					parent[v.first] = u;
					lastvisited[v.first] = v.second;
					pq.push(make_pair(dist[v.first], ii(v.second, v.first)));
				} 
			}
		}	
		bool ans = true;
		int total = 0;
		F(i, 1, n){
			if (lastvisited[i] == INF)
			{
				printf("NO\n");
				ans = false;
			}	
			total += lastvisited[i];
		}
		if (!ans)
		{
			continue;
		}
		if (total == mst)
		{
			printf("YES\n");
		} else {
			printf("NO\n");
		}
    }
    return 0;          
}/*
    Still TLE - Probably need to use Prims instead of Kruskal.
*/
 