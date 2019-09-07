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

const int N = 100;
int mat[N][N];
bool visited[N][N][4], steady[N][N];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

bool valid(int cx, int cy, int n) {
	return (cx >= 0 && cx < n && cy >= 0 && cy < n);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n; cin>>n;
	ii s,e; cin>>s.ff>>s.ss>>e.ff>>e.ss;
	memset(visited, false, sizeof(visited));
	memset(steady, false, sizeof(steady));
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			cin>>mat[i][j];
			if (i == s.ff && j == s.ss)
			{
				FOR(k, 0, 4) visited[i][j][k] = true;
				steady[i][j] = true;
			}
		}
	}
	queue<ii> q; q.push(s);
	while(!q.empty()) {
		ii curr = q.front(); q.pop();

		FOR(dir, 0, 4) {
			int nx = curr.ff + dx[dir];
			int ny = curr.ss + dy[dir];
			if(valid(nx, ny, n) && !visited[nx][ny][dir] && mat[nx][ny] == 0) {
				visited[nx][ny][dir] = true;
				q.push({nx, ny});
				int nxx = nx + dx[dir]; int nyy = ny + dy[dir];
				steady[nx][ny] = (!valid(nxx, nyy, n) || mat[nxx][nyy] == 1);
			}
		}
	}

	if (steady[e.ff][e.ss])
	{
		cout<<"YES";
	} else {
		cout<<"NO";
	}
    return 0;
}