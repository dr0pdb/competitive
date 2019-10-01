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

const int N = 7001;
int n,u,v;
ll a[N]; int b[N];
bool mat[N][N], incoming[N][N];
int out[N];
bool del[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    FOR(i, 0, n) cin>>a[i];
    FOR(i, 0, n) cin>>b[i];
    memset(del, false, sizeof(del)); memset(out, 0, sizeof(out));
    memset(mat, 0, sizeof(mat)); memset(incoming, false, sizeof(incoming));

    FOR(i, 0, n) {
    	FOR(j, i+1, n) {
    		if((a[i] & a[j]) != a[i]) {
    			mat[i][j] = true;
    			incoming[j][i] = true;
    			out[i]++;
    		}
    		if((a[i] & a[j]) != a[j]) {
    			mat[j][i] = true;
    			incoming[i][j] = true;
    			out[j]++;
    		}
    	}
    }

    int curr, curval = 0; int remainingn = n;
    FOR(i, 0, n) {
    	curval = INF; curr = -1;
    	FOR(j, 0, n) {
    		if(del[j]) continue;
    		if(out[j] == remainingn - 1) {
				if(curval > b[j]) {
					curval = b[j];
					curr = j;
				}
    		} 
    	}
    	if(curr == -1) break;
    	del[curr] = true;
    	FOR(u, 0, n) {
    		if(!incoming[curr][u]) continue;
    		if(mat[u][curr]) {
    			mat[u][curr] = 0;
    			out[u]--;
    		}
    		incoming[curr][u] = false;
    	}
    	remainingn--;
    }
    ll ans = 0, cnt = 0;
    FOR(i, 0, n) {
    	if(!del[i]) {
    		cnt++;
    		ans += (ll)b[i];
    	}
    }
    if(cnt <= 1) ans = 0;
    cout<<ans;
    return 0;
}