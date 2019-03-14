#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 1005;
int s[10],n,m,p;
char mat[N][N];
int st[N][N];
typedef pair<ii,ii> iiii;

bool cmp(iiii a, iiii b) {
	return (a.first.first > b.first.first ||
	 	(a.first.first == b.first.first && a.first.second > b.first.second));
}

priority_queue<iiii, vector<iiii>, std::function<bool(iiii, iiii) >> pq(cmp);

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool valid(int cx, int cy) {
	return cx >= 0 && cx < n && cy >= 0 && cy < m;
}

void mark(int cx, int cy, int steps, int t, int num) {
	if(steps == 0) return;

	F(i, 0, 4) {
		int nx = cx, ny = cy;
		nx += dx[i]; ny += dy[i];

		if(valid(nx, ny) && (mat[nx][ny] == '.' || (mat[nx][ny] == (char)(num+'1') && steps > st[nx][ny]))) {
			mat[nx][ny] = (char)(num + '1');
			pq.push({{t+1, num}, {nx, ny}});
			st[nx][ny] = steps;
			mark(nx, ny, steps-1, t, num);
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>p;

    F(i, 0, p) {
    	cin>>s[i];
    }

    F(i, 0, n) {
    	F(j, 0, m) {
    		cin>>mat[i][j];
    		if(mat[i][j] == '.' || mat[i][j] == '#') continue;
    		pq.push({{0, mat[i][j]-'1'}, {i,j}});
    	}
    }

    memset(st, 0, sizeof(st));

    while(!pq.empty()) {
    	iiii curr = pq.top(); pq.pop();
    	int t = curr.first.first, num = curr.first.second;
    	int cx = curr.second.first, cy = curr.second.second;
    	mark(cx, cy, s[num], t, num);
    }

    int cnt[10];
    memset(cnt, 0, sizeof(cnt));

    F(i, 0, n) {
    	F(j, 0, m) {
    		// cout<<mat[i][j]<<" ";
    		if(mat[i][j] == '#') continue;
    		cnt[mat[i][j]-'1']++;
    	}
    	// cout<<endl;
    }

    F(i, 0, p) {
    	cout<<cnt[i]<<" ";
    }

    return 0;
}/*

*/