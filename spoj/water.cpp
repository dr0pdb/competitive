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

const int N = 105;
int mat[N][N],n,m,t;
bool done[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vii neighbours(int cx, int cy) {
	vii ret; int nx, ny;
	FOR(i, 0, 4) {
		nx = cx + dx[i];
		ny = cy + dy[i];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && !done[nx][ny]) {
			ret.push_back({nx,ny});
		}
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>t;

    while(t--) {
    	cin>>n>>m;
    	memset(done, false, sizeof(done));
    	priority_queue<iii, vector<iii>, greater<iii> > pq;
    	FOR(i, 0, n) {
    		FOR(j, 0, m) {
    			cin>>mat[i][j];
    			if(i == 0 || i == n-1 || j == 0 || j == m - 1) {
    				pq.push({mat[i][j], {i,j}});
    				done[i][j] = true;
    			}
    		}
    	}
    	int ans = 0;
    	while(!pq.empty()) {
    		iii curr = pq.top(); pq.pop();
    		int ht = curr.ff; int cx = curr.ss.ff, cy = curr.ss.ss, nx,ny;
    		vii ngh = neighbours(cx, cy);
    		// deb(cx); deb(cy);
    		for(auto nxt : ngh) {
    			tie(nx,ny) = nxt;
    			// deb(nx); deb(ny);
    			if(mat[nx][ny] < mat[cx][cy]) {
    				ans += mat[cx][cy] - mat[nx][ny];
    				mat[nx][ny] = mat[cx][cy];
    			}
    			pq.push({mat[nx][ny], {nx, ny}});
    			done[nx][ny] = true;
    		}
    	}

    	cout<<ans<<endl;
    }

    return 0;
}