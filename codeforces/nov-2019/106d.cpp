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
int n,m;
char mat[N][N];
map<char, ii> sights;
vector<pair<char,int> > ins;
map<char, int> dir = {
    {'N', 0},
    {'E', 1},
    {'W', 3},
    {'S', 2},
};

// last vertex reachable in each of the 4 directions from [i][j]
ii lastreachable[4][N][N]; // 0 : North, 1 : East, 3 : west and 2 : south.

bool update(int &u, int &v, pair<char,int> in) {
    int d = dir[in.ff];
    int jump = in.ss; bool good = true;

    if(in.ff == 'N') {
        if(lastreachable[d][u][v] > ii(u - jump, v)) good = false;
        u -= jump; 
    } else if(in.ff == 'E') {
        if(lastreachable[d][u][v] < ii(u, v + jump)) good = false;
        v += jump;
    } else if(in.ff == 'W') {
        if(lastreachable[d][u][v] > ii(u, v - jump)) good = false;
        v -= jump;
    } else {
        if(lastreachable[d][u][v] < ii(u + jump, v)) good = false;
        u += jump;
    }
    if(mat[u][v] == '#') good = false;
    return good;
}

void build() {
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            lastreachable[0][i][j] = {i, j};
            lastreachable[3][i][j] = {i, j};
            if(mat[i][j] == '#') continue;
            if(i > 0 && mat[i-1][j] != '#') { // north
                lastreachable[0][i][j] = lastreachable[0][i-1][j];
            }
            if(j > 0 && mat[i][j-1] != '#') { // west
                lastreachable[3][i][j] = lastreachable[3][i][j-1];
            }
        }
    }
    RFOR(i, n-1, 0) {
        RFOR(j, m-1, 0) {
            lastreachable[2][i][j] = {i, j};
            lastreachable[1][i][j] = {i, j};

            if(mat[i][j] == '#') continue;
            if(i + 1 < n && mat[i+1][j] != '#') { // south
                lastreachable[2][i][j] = lastreachable[2][i+1][j];
            }
            if(j + 1 < m && mat[i][j+1] != '#') { // east
                lastreachable[1][i][j] = lastreachable[1][i][j+1];
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin>>mat[i][j];
            if(mat[i][j] != '#' && mat[i][j] != '.') {
                sights[mat[i][j]] = {i, j};
            }
        }
    }
    build();
    // FOR(k, 0, 4) {
    //     FOR(i, 0, n) {
    //        FOR(j, 0, m) {
    //             cout<<"{"<<lastreachable[k][i][j].ff<<" "<<lastreachable[k][i][j].ss<<"}  ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl<<endl;
    // }
    int k; cin>>k; ins.resize(k);
    FOR(i, 0, k) {
        cin>>ins[i].ff>>ins[i].ss;
    }
    string res; int u,v;
    for(auto sight : sights) {
        tie(u, v) = sight.ss;
        bool poss = true;

        FOR(i, 0, k) {
            if(!update(u, v, ins[i])) {
                poss = false;
                break;
            }
        }

        if(poss) {
            res.push_back(sight.ff);
        }
    }
    if(res.empty()) res = "no solution";
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}