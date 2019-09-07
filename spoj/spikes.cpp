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

const int N = 45;
char mat[N][N];
int dist[N][N],n,m,j,x,y;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool valid(int nx, int ny) {
	return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>j;
    queue<ii> q;
    FOR(i, 0, n) {
    	FOR(j, 0, m) {
    		dist[i][j] = INF;
    		cin>>mat[i][j];
    		if (mat[i][j] == '@')
    		{
    			q.push({i,j});
    			dist[i][j]=0;
    		}
    	}
    }
    while(!q.empty()) {
    	tie(x,y) = q.front(); q.pop();
    	FOR(i, 0, 4) {
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		if (valid(nx,ny) && mat[nx][ny] != '#' && (dist[nx][ny] > dist[x][y] + (mat[x][y] == 's')))
    		{
    			dist[nx][ny] = dist[x][y] + (mat[x][y] == 's');
    			q.push({nx,ny});
    			if (mat[nx][ny] == 'x' && dist[nx][ny] <= j/2)
				{
					cout<<"SUCCESS";
					return 0;
				}	
    		}
    	}
    }
    cout<<"IMPOSSIBLE";
    return 0;
}