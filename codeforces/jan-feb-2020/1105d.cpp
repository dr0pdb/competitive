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

const int N = 1001;
int visited[N][N];
char arr[N][N];
int s[N];
int n,m,p;
vector<queue<iii>> q;

int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

bool valid(int nx, int ny) {
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m>>p;
    vector<vii> starters(p);
    vi res(p, 0);
    FOR(i, 0, p) cin>>s[i];
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin>>arr[i][j];
            if(arr[i][j] == '.' || arr[i][j] == '#') continue;
            int idx = (arr[i][j] - '1');
            starters[idx].push_back({i, j});
        }
    }
    memset(visited, -1, sizeof(visited));
    q.resize(p);
    FOR(i, 0, p) {
        for(ii a : starters[i]) {
            visited[a.ff][a.ss] = i;
            res[i]++;
            q[i].push({s[i], a});
        }
    }
    int turn = 0, a, b, cnt = 0;
    while(true) {
        if(q[turn].empty()) {
            turn++; turn %= p;
            cnt++;
            if(cnt >= p) break;
            continue;
        }
        cnt = 0;
        vii boundary;

        while(!q[turn].empty()) {
            tie(a, b) = q[turn].front().ss;
            int steps = q[turn].front().ff; q[turn].pop();
            if(steps == 0) boundary.push_back({a, b});

            if(steps > 0) {
                FOR(d, 0, 4) {
                    int na = a + dx[d]; int nb = b + dy[d];
                    if(valid(na, nb) && visited[na][nb] == -1 && arr[na][nb] == '.') {
                        visited[na][nb] = turn;
                        res[turn]++;
                        q[turn].push({steps - 1, {na, nb}});
                    }
                }
            }
        }

        for(auto a : boundary) {
            q[turn].push({s[turn], a});
        }

        turn++; turn %= p;
    }
    for(auto r : res) cout<<r<<" ";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}