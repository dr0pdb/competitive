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

int mat[1001][1001];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int h,w; cin>>h>>w;
    int r[h], c[w];
    bool pos = true;
    memset(mat, -1, sizeof(mat));
    FOR(i, 0, h) {
    	cin>>r[i];
    	FOR(j, 0, r[i]) {
    		if(mat[i][j] == 0) pos = false;
    		mat[i][j] = 1;
    	}
    	if(r[i] < w) {
    		if(mat[i][r[i]] == 1) pos = false;
    		mat[i][r[i]] = 0;
    	}
    }
    FOR(i, 0, w) {
    	cin>>c[i];
    	FOR(j, 0, c[i]) {
    		if(mat[j][i] == 0) pos = false;
    		mat[j][i] = 1;
    	}
    	if(c[i] < h) {
    		if(mat[c[i]][i] == 1) pos = false;
    		mat[c[i]][i] = 0;
    	}
    }
    int res = 1;
    if (pos)
    {
    	FOR(i, 0, h) {
    		FOR(j, 0, w) {
    			if(mat[i][j] == -1) {
    				res *= 2LL;
    				res %= MOD;
    			}
    		}
    	}
    } else res = 0;
    cout<<res;
    return 0;
}