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
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

#define OUT 0
const int N = 2e5+5;
ll dp[2][N]; // 0: reps addition in both x and y. 1: reps addition in y and sub in x.
int n, arr[N];
int g[2][N];
bool onstack[2][N];

void dfs(int turn, int curr) {
    onstack[turn][curr] = true;
    
    dp[turn][curr] = 0;
    int nxt = g[turn][curr];
    
    if(nxt == OUT) {
        dp[turn][curr] = arr[curr];
    } else {
        if(nxt == 1) dp[turn][curr] = -1;
        else if(dp[1-turn][nxt] != -2) {
            if(onstack[1-turn][nxt] || dp[1-turn][nxt] == -1) {
                dp[turn][curr] = -1; // cycle
            } else {
                dp[turn][curr] = arr[curr] + dp[1-turn][nxt];
            }
        } else {
            dfs(1 - turn, nxt);
            if(dp[1-turn][nxt] == -1) dp[turn][curr] = -1;
            else 
                dp[turn][curr] = arr[curr] + dp[1-turn][nxt];
        }
    }
    onstack[turn][curr] = false;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    FOR(i, 2, n+1) {
        cin>>arr[i];
    }
    memset(onstack, false, sizeof(onstack));
    FOR(i, 2, n+1) {
        g[0][i] = i + arr[i];
        g[1][i] = i - arr[i];
        dp[0][i] = dp[1][i] = -2;
        if(g[0][i] > n) g[0][i] = OUT;
        if(g[1][i] <= 0) g[1][i] = OUT;
    }
    FOR(i, 2, n+1) {
        if(dp[1][i] == -2) dfs(1, i);
    }
    FOR(i, 1, n) {
        ll res = dp[1][i+1];
        if(res != -1) res += i;
        cout<<res<<endl;
    }
    return 0;
}