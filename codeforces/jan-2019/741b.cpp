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

const int MaxN = 1e3;

int dp[MaxN + 1][MaxN + 1];

vector<vector<int> > groups;
int weight[MaxN];
int beauty[MaxN];

bool used[MaxN];

vector<int> cur;
vector<vector<int> > g;

void dfs(int v) {
    used[v] = true;
    cur.push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

int main() {
    int n, m, w;
    cin >> n >> m >> w;

    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> beauty[i];
    }

    g.resize(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    for (int i = 0; i < n; ++i) {
        cur.clear();
        if (!used[i])
            dfs(i);
        groups.push_back(cur);
    }

    for (int i = 1; i <= (int)groups.size(); ++i) {
        for (int j = 0; j <= w; ++j) {
            int sumw = 0;
            int sumb = 0;
            dp[i][j] = dp[i - 1][j];
            for (int t = 0; t < groups[i - 1].size(); ++t) {
                int cur = groups[i - 1][t];
                sumw += weight[cur];
                sumb += beauty[cur];
                if (weight[cur] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[cur]] + beauty[cur]);
                }
            }
            if (sumw <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - sumw] + sumb);
            }
        }
    }

    cout << dp[(int)groups.size()][w] << endl;

    return 0; 
}