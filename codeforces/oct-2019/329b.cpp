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

int dirx[4] = {0, 1, -1, 0};
int diry[4] = {1, 0, 0, -1};

const int N = 1e3+5;
char mat[N][N];
int r,c,u,v;
ii start, target;
int dist[N][N];

bool valid(int nx, int ny) {
    return (nx >= 0 && nx < r && ny >= 0 && ny < c);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>r>>c;
    FOR(i, 0, r) {
        FOR(j, 0, c) {
            cin>>mat[i][j];
            if(mat[i][j] == 'S') start = {i,j};
            else if(mat[i][j] == 'E') target = {i,j};
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<ii> q; q.push(target);
    dist[target.ff][target.ss] = 0;
    while(!q.empty()) {
        tie(u,v) = q.front(); q.pop();
        FOR(d, 0, 4) {
            int nx = u + dirx[d]; int ny = v + diry[d];
            if(valid(nx, ny) && mat[nx][ny] != 'T' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[u][v] + 1;
                q.push({nx, ny});
            }
        }
    }
    int res = 0;
    FOR(i, 0, r) {
        FOR(j, 0, c) {
            if(isdigit(mat[i][j]) && dist[i][j] >= 0 && dist[i][j] <= dist[start.ff][start.ss]) {
                res += mat[i][j] - '0';
            }
        }
    }
    cout<<res;
    return 0;
}