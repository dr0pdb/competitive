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

const int N = 2e5+5;
int n,m,u,v;
vi g[N]; vii ans;
int degree[N];
bool used[N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    used[src] = true;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        
        for(auto next : g[curr]) {
            if(!used[next]) {
                used[next] = true;
                ans.push_back({curr, next});
                q.push(next);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    memset(degree, 0, sizeof(degree));
    memset(used, false, sizeof(used));

    F(i, 0, m) {
    	cin>>u>>v; u--; v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
        degree[u]++; degree[v]++;
    }

    int src = max_element(degree, degree+n) - degree;
    bfs(src);

    F(i, 0, ans.size()) {
    	cout<<ans[i].first + 1<<" "<<ans[i].second + 1<<endl;
    }

    return 0;
}/*

*/