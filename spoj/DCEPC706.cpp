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

const int N = 205;
char mat[N][N];
int n,m,dist[3][N][N], tx,ty,tnx,tny,ans;
bool visited[3][N][N];

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};

bool valid() {
	return (tnx >= 0 && tnx <= m + 1 && tny >= 0 && tny <= n + 1 && mat[tnx][tny] != '#');
}

bool check(int i, int j) {
	bool ret = true;
	FOR(k, 0, 3) {
		ret &= visited[k][i][j];
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--) {
    	cin>>m>>n;
    	FOR(k, 0, 3) {
    		FOR(i, 0, N) {
    			FOR(j, 0, N) {
    				dist[k][i][j] = INF;
    			}
    		}
    	}
    	memset(visited, false, sizeof(visited));
    	queue<iii> q;
    	bool done = false;
    	memset(mat, '.', sizeof(mat));
    	FOR(i, 1, m+1) {
    		FOR(j, 1, n+1) {
    			cin>>mat[i][j];
    			if(mat[i][j] == '1') {
    				dist[0][i][j]=0;
    				visited[0][i][j]=true;
    				q.push({0, {i,j}});
    				done = check(i,j);
    			} else if (mat[i][j] == '2') {
    				dist[1][i][j]=0;
    				visited[1][i][j]=true;
    				q.push({1, {i, j}});
    				done = check(i,j);
    			} else if (mat[i][j] == '3') {
    				dist[2][i][j]=0;
    				visited[2][i][j]=true;
    				q.push({2, {i,j}});
    				done = check(i,j);
    			}
    		}
    	}
    	if(done) {
    		cout<<0<<endl;
    		continue;
    	}

		while(!q.empty()) {
			if(done) break;
			iii curr = q.front(); q.pop();
			int person = curr.first;
			tx = curr.ss.ff;
			ty = curr.ss.ss;
			
			FOR(d, 0, 4) {
				tnx = tx + dirx[d];
				tny = ty + diry[d];

				if(valid() && !visited[person][tnx][tny]) {
					visited[person][tnx][tny]=true;
					dist[person][tnx][tny]=dist[person][tx][ty]+1;
					q.push({person, {tnx, tny}});
					bool tobreak = true;
					ans = -1;
					FOR(i, 0, 3) {
						tobreak &= (visited[i][tnx][tny]);
					}
					if (tobreak)
					{
						ans = dist[person][tnx][tny];
						done = true;
						break;
					}
				}
			}
		}

		cout<<ans<<endl;
    }

    return 0;
}