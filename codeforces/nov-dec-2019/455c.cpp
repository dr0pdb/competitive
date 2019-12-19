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

const int N = 3e5+5;
int n,m,q;
vi g[N];

const int FINDSIZE = N;
int p[FINDSIZE], sizes[FINDSIZE], diameter[FINDSIZE];

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
        diameter[i] = 0;
	}
}

int dist[N],maxdi, maxd, dist2[N];

void dfs(int curr) {
    for(int nxt : g[curr]) {
        if(dist[nxt] == -1) {
            join(nxt, curr);
            dist[nxt] = dist[curr] + 1;
            if(maxd < dist[nxt]) {
                maxd = dist[nxt]; maxdi = nxt;
            }
            dfs(nxt);
        }
    }
}

void dfs2(int curr) {
    for(int nxt : g[curr]) {
        if(dist2[nxt] == -1) {
            dist2[nxt] = dist2[curr] + 1;
            maxd = max(dist2[nxt], maxd);
            dfs2(nxt);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int a,b,t;
    cin>>n>>m>>q;
    initialiseUnionFind();
    FOR(i, 0, m) {
        cin>>a>>b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dist, -1, sizeof(dist)); memset(dist2, -1, sizeof(dist2));
    FOR(i, 0, n) {
        if(dist[i] == -1) {
            dist[i] = 0; maxd = 0, maxdi = i;
            dfs(i);
            // deb(maxd); deb(maxdi);
            dist2[maxdi] = 0; maxd = 0;
            dfs2(maxdi);
            // deb(maxd);
            diameter[findSet(i)] = maxd;
        }
    }
    FOR(i, 0, q) {
        cin>>t>>a; a--;
        int pa = findSet(a);
        if(t == 1) {
            cout<<diameter[pa]<<endl;
        } else {
            cin>>b; b--;
            int pb = findSet(b);
            if(pa == pb) continue; // wtf
            int d1 = diameter[pa]; int d2 = diameter[pb];
            diameter[pa] = max(d1, d2); diameter[pb] = max(d1, d2);
            join(pa, pb);
            int np = findSet(pa);
            if((d1+1)/2 + (d2+1)/2 + 1 > max(d1, d2)) {
                diameter[np] = (d1+1)/2 + (d2+1)/2 + 1;
            }
        }
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}