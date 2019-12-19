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
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
vi g[N];
int n, arr[N],idx,ans[N];
int dist[N][2];
bool visited[N];

void bfs() {
    queue<int> q;
    FOR(i, 0, n) {
        if(arr[i] % 2 == idx) {
            dist[i][idx] = 0;
            q.push(i);
            visited[i] = true;
        }
    }
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int nxt : g[curr]) {
            if(!visited[nxt]) {
                visited[nxt] = true;
                dist[nxt][idx] = dist[curr][idx] + 1;
                q.push(nxt);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n;
    FOR(i, 0, n) {
        cin>>arr[i];
        if(i - arr[i] >= 0) g[i - arr[i]].push_back(i);
        if(i + arr[i] < n) g[i + arr[i]].push_back(i);
        dist[i][0] = dist[i][1] = INF;
    }
    idx = 0; memset(visited, false, sizeof(visited));
    bfs();
    idx = 1; memset(visited, false, sizeof(visited));
    bfs();
    FOR(i, 0, n) {
        if(arr[i] % 2 == 1) {
            if(dist[i][0] == INF) ans[i] = -1;
            else ans[i] = dist[i][0];
        } else {
            if(dist[i][1] == INF) ans[i] = -1;
            else ans[i] = dist[i][1];
        }
    }
    FOR(i, 0, n) {
        cout<<ans[i]<<" ";
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}