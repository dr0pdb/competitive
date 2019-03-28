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

typedef pair<ii,ii> quad;
const int N = 21;
char mat[N][N];
bool visited[N][N][N][N];
int dist1[N][N], dist2[N][N];
int n,m,x[2],y[2];
ii a,b;

int dirx[5] = {0, -1, 0, 1, 0};
int diry[5] = {0, 0, 1, 0, -1};

bool valid(int nx[2], int ny[2]) {
	return ((nx[0]>=0 && nx[0]<n && ny[0]>=0 && ny[0]<m) && (nx[1]>=0 && nx[1]<n && ny[1]>=0 && ny[1]<m));
}

bool not_cross(int nx[2], int ny[2]) {
	return !((x[0] == nx[1] && y[0] == ny[1]) || (x[1] == nx[0] && y[1] == ny[0]));
}

bool vacant(int nx[2], int ny[2]) {
	return (mat[nx[0]][ny[0]] != '#' && mat[nx[1]][ny[1]] != '#' && not_cross(nx, ny));
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(cin>>n>>m && (n + m)) {
    	FOR(i, 0, n) {
    		FOR(j, 0, m) {
    			cin>>mat[i][j];
    			dist1[i][j] = INF;
    			dist2[i][j] = INF;
    			if(mat[i][j] == 'a') {
    				a = {i, j};
    				dist1[i][j]=0;
    			} else if (mat[i][j] == 'b')
    			{
    				b = {i, j};
    				dist2[i][j]=0;
    			}
    		}
    	}

		queue<quad> q;
    	memset(visited, false, sizeof(visited));
    	q.push({a, b});
    	visited[a.first][a.second][b.first][b.second] = true;
    	while(!q.empty()) {
    		quad curr = q.front(); q.pop();
    		x[0] = curr.ff.ff;
    		x[1] = curr.ss.ff;
    		y[0] = curr.ff.ss;
    		y[1] = curr.ss.ss;

    		FOR(adir, 0, 5) {
    			FOR(bdir, 0, 5) {
    				int nx[2],ny[2];
    				nx[0] = x[0] + dirx[adir];
    				nx[1] = x[1] + dirx[bdir];
    				ny[0] = y[0] + diry[adir];
    				ny[1] = y[1] + diry[bdir];

    				if(valid(nx, ny) && vacant(nx, ny) && !visited[nx[0]][ny[0]][nx[1]][ny[1]]) {
    					dist1[nx[0]][ny[0]] = min(dist1[x[0]][y[0]]+1, dist1[nx[0]][ny[0]]);
    					dist2[nx[1]][ny[1]] = min(dist2[x[1]][y[1]]+1, dist2[nx[1]][ny[1]]);    					
    					visited[nx[0]][ny[0]][nx[1]][ny[1]] = true;
    					q.push({{nx[0], ny[0]}, {nx[1], ny[1]}});
    				}
    			}
    		}
    	}

    	if(!visited[b.first][b.second][a.first][a.second]) {
    		cout<<"IMPOSSIBLE\n";
    	} else {
    		cout<<max(dist2[a.first][a.second], dist1[b.first][b.second])<<endl;
    	}
    }

    return 0;
}

/*
#include<cstdio>
#include<queue>
#include<list>
#include<cstring>
using namespace std;

#define gc getchar_unlocked

char arr[20][20];
int dist[160000],n,m;

inline list<int> generate_moves(int x, int y){
	list<int> moves;
	moves.push_back(x*20+y);
	if(x>0 && !(arr[x-1][y]=='#'))
		moves.push_back((x-1)*20+y);
	if(x<(n-1) && !(arr[x+1][y]=='#'))
		moves.push_back((x+1)*20+y);
	if(y>0 && !(arr[x][y-1]=='#'))
		moves.push_back((x)*20+y-1);
	if(y<(m-1) && !(arr[x][y+1]=='#'))
		moves.push_back((x)*20+y+1);
	return moves;
}

inline int hash(int ax, int ay, int bx, int by){
	return by + bx*20 + ay*400 + ax*8000;
}

inline int scan_char(){
	register int c;
	do{
		c = gc();
	}while(c<=32);
	return c;
}

inline void bfs(int ax1, int ay1, int bx1, int by1){
	queue<int> q;
	int ha = hash(ax1,ay1,bx1,by1);
	q.push(ha);
	dist[ha] = 0;
	while(!q.empty()){
		int h1 = q.front(),h=h1;
		q.pop();
		int ax,ay,bx,by;
		by = h%20;
		h/=20;
		bx = h%20;
		h/=20;
		ay = h%20;
		h/=20;
		ax = h;
		list<int> a_moves = 	generate_moves(ax,ay);
		list<int> b_moves =	generate_moves(bx,by);
		for(list<int>::iterator i1 = a_moves.begin();i1!=a_moves.end();i1++){
			for(list<int>::iterator i2 = b_moves.begin();i2!=b_moves.end();i2++){
				int temp = (*i1)*400 + *i2;
				if((*i1)==(*i2)) continue;
				if((*i1)==(bx*20+by) && (*i2)==(ax*20+ay)) continue;
				if(dist[temp]==-1){
					dist[temp] = dist[h1]+1;
					q.push(temp);
				}
			}
		}
	}
}

inline int calc_moves(int ax, int ay, int bx, int by){
	memset(dist,-1,sizeof(dist));
	bfs(ax,ay,bx,by);
	return dist[hash(bx,by,ax,ay)];
}

int main(){
	while(1){
		scanf("%d %d",&n,&m);
		int ax,ay,bx,by;
		if(!(n||m)) break;
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				arr[i][j] = scan_char();
				if(arr[i][j]=='a'){
					ax = i;
					ay = j;
				}
				if(arr[i][j]=='b')
				{
					bx = i;
					by = j;
				}
			}
		int moves = calc_moves(ax,ay,bx,by);
		if(moves>0){
			printf("%d\n",moves);
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}



*/