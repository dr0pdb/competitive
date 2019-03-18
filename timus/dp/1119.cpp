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

const int N = 1005;
double dist[N][N];
bool crossable[N][N];
int n,m,k,x,y;
const double diagcost = 100*sqrt(2.0);

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m>>k;
    memset(crossable, false, sizeof(crossable));

    FOR(i, 0, k) {
    	cin>>x>>y; x--; y--;
    	crossable[x][y] = true;
    }

    FOR(i, 0, n+1) {
    	FOR(j, 0, m+1) {
    		dist[i][j] = LONG_LONG_MAX;
    	}
    }

    dist[0][0]=0;
   	FOR(i, 0, n+1) {
   		FOR(j, 0, m+1) {
   			if(!(i+j)) {
   				continue;
   			}

   			if(i) {
   				dist[i][j] = min(dist[i][j], dist[i-1][j] + 100);
   			}

   			if(j) {
   				dist[i][j] = min(dist[i][j], dist[i][j-1] + 100);
   			}

   			if(i && j && crossable[i-1][j-1]) {
   				dist[i][j] = min(dist[i][j], dist[i-1][j-1] + diagcost);
   			}
   		}
   	}

    cout<<round(dist[n][m]);

    return 0;
}