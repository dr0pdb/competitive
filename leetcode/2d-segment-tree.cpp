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
int st[4*N][4*N], matrix[N][N];
int n,m; // row amd columns

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
	if(ly == ry) {
		if(lx == rx) {
			st[vx][vy] = matrix[lx][ly];
		} else {
			st[vx][vy] = st[2*vx][vy] + st[2*vx+1][vy];
		}
	} else {
		int my = (ly + ry)/ 2;
		build_y(vx, lx, rx, 2*vy, ly, my);
		build_y(vx, lx, rx, 2*vy+1, my+1, ry);
		st[vx][vy] = st[vx][2*vy] + st[vx][2*vy+1];
	}
}

void build_x(int vx, int lx, int rx) {
	if(lx != rx) {
		int mx = (lx + rx) / 2;
		build_x(2*vx, lx, mx);
		build_x(2*vx + 1, mx + 1, rx);
	}
	build_y(vx, lx, rx, 1, 0, m-1);
}

int sum_y(int vx, int vy, int ly, int ry, int qly, int qry) {
	if(ry < qly || ly > qry) return 0;
	if(qly == ly && qry == ry) {
		return st[vx][vy];
	}
	int my = (ly + ry)/2;
	int res1 = sum_y(vx, 2*vy, ly, my, qly, qry);
	int res2 = sum_y(vx, 2*vy+1, my+1, ry, qly, qry);
	return res1 + res2;
}

int sum_x(int vx, int lx, int rx, int qlx, int qrx, int qly, int qry) {
	if(rx < qlx || lx > qrx) return 0;
	if(qlx == lx && qrx == rx) {
		return sum_y(vx, 1, 0, m-1, qly, qry);
	}
	int mx = (lx + rx) / 2;
	int res1 = sum_x(2*vx, lx, mx, qlx, min(qrx, mx), qly, qry);
	int res2 = sum_x(2*vx+1, mx+1, rx, qlx, max(mx+1, qrx), qly, qry);
	return res1 + res2;
}

void update_y(int vx, int vy, int ly, int ry, int ux, int uy) {
	if(ry < uy || ly > uy) return;
	if(ly == ry) {
		st[vx][vy] = matrix[ux][uy];
	} else {
		int my = (ly + ry)/ 2;
		update_y(vx, 2*vy, ly, my, ux, uy);
		update_y(vx, 2*vy+1, my+1, ry, ux, uy);
		st[vx][vy] = st[vx][2*vy] + st[vx][2*vy+1];
	}
}

void update_x(int vx, int lx, int rx, int ux, int uy) {
	if(rx < ux || lx > ux) return;
	if(lx == rx) {
		update_y(vx, 1, 0, m-1, ux, uy);
		return;
	}
	int mx = (lx + rx )/ 2;
	update_x(2*vx, lx, mx, ux, uy);
	update_x(2*vx+1, mx+1, rx, ux, uy);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin>>n>>m;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin>>matrix[i][j];
		}
	}


    return 0;
}