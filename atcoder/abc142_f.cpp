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

const int N = 1001;
vi g[N];
vi res;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n,m,a,b; cin>>n>>m;
	FOR(i, 0, m) {
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
	}

	FOR(i, 0, n) {
		queue<int> q;
		vector<int> dist(n, -1);
		vector<int> p(n, -1);

		q.push(i); dist[i] = 0; bool found = false;
		while(!q.empty() && !found) {
			int curr = q.front(); q.pop();
			for(int nxt : g[curr]) {
				if(dist[nxt] == -1) {
					dist[nxt] = dist[curr] + 1;
					p[nxt] = curr;
					q.push(nxt);
				} else if(nxt == i) {
					vector<int> nodes;
					int c = curr;
					while(c != -1) {
						nodes.push_back(c);
						c = p[c];
					}
					if(res.empty() || nodes.size() < res.size()) {
						res = nodes;
					}
					found = true;
					break;
				}
			}
		}
	}
	if(res.empty()) cout<<-1;
	else {
		cout<<res.size()<<endl;
		FOR(i, 0, res.size()) cout<<res[i] + 1<<endl;
	}
    return 0;
}