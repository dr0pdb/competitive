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

const int N = 255;
int arr[N][N], dist[N][N],t,r,c,ans,u,v;
vii sources;
bool visited[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ii maxnode;

bool valid(int nx, int ny) {
	return (nx >= 0 && nx < r && ny >= 0 && ny < c);
}

void computeDistance() {
	memset(visited, false, sizeof(visited));
	queue<iii> q;
	FOR(i, 0, sources.size()) {
		tie(u,v) = sources[i];
		q.push({i, {u,v}});
		visited[u][v]=true;
	}

	while(!q.empty()) {
		int src;
		iii tmp = q.front(); q.pop();
		src = tmp.first;
		tie(u,v) = tmp.second;

		FOR(dir, 0, 4) {
			int nx = u + dx[dir];
			int ny = v + dy[dir];
			if(valid(nx,ny) && !visited[nx][ny]) {
				visited[nx][ny]=true;
				dist[nx][ny] = min(dist[nx][ny], abs(nx - sources[src].first) + abs(ny - sources[src].second));
				ans = max(ans, dist[nx][ny]);
				if(dist[nx][ny] == ans) {
					maxnode = {nx,ny};
				}
				q.push({src,{nx,ny}});
			}
		}
	}
}

int main(){
    cin>>t;

    FOR(tn, 1, t+1) {
    	cin>>r>>c;
    	sources.clear();
    	ans = INF;

    	FOR(i, 0, r) {
    		FOR(j, 0, c) {
    			scanf("%1d", &arr[i][j]);
    			if(arr[i][j]) {
    				dist[i][j]=0;
    				ans = 0;
    				sources.push_back({i,j});
    			} else {
    				dist[i][j]=INF;
    			}
    		}
    	}

    	if(sources.size() != 0) {
    		computeDistance();
	    	if(ans > 0) {
	    		int ans2 = 0;
	    		tie(u,v) = maxnode;
	    		FOR(i, 0, r) {
	    			FOR(j, 0, c) {
	    				int d = min((ll)dist[i][j], abs(i - u) + abs(j - v));
	    				ans2 = max(ans2, d);
	    			}
	    		}
	    		ans = min(ans, ans2);
	    	}
    	} else {
    		ans = (r/2) + (c/2);
    	}

    	

    	cout<<"Case #"<<tn<<": "<<ans<<endl;
    }

    return 0;
}