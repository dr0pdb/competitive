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

struct tour {
    long double prob;
    int prize;
};

const int N = 205;
int n,l,k;
tour t[N];
//dp[i][j][k]: prob of winning j tours out of first i using k-spaces. k is min(k, 201) because we won't need more than 201 space.
long double dp[N][N][N];
bool done[N][N][N];

long double solve(int idx, int wins, int space) {
    if(space < 0) return 0; // possible because of sorting.
    if(idx == n) return wins >= l;
    long double &ret = dp[idx][wins][space];
    if(done[idx][wins][space]) return ret;
    done[idx][wins][space] = true; ret = 0;

    // win this
    if(t[idx].prize == -1) {
        ret += t[idx].prob * solve(idx + 1, wins + 1, space - 1);
    } else {
        ret += t[idx].prob * solve(idx + 1, wins + 1, min(201, space + t[idx].prize)); // 5 wrong answers because I wrote max(201, ...)
    }

    // lose this
    ret += (1 - t[idx].prob) * solve(idx + 1, wins, space);

    return ret;
}

bool cmp(tour a, tour b) {
    return a.prize > b.prize;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n>>l>>k;
    FOR(i, 0, n) {
        cin>>t[i].prob;
        t[i].prob /= 100.0;
    }
    FOR(i, 0, n) {
        cin>>t[i].prize;
    }
    sort(t, t+n, cmp); // putting all the prized one first allows exiting when space < 0 in the recursion.
    memset(done, false, sizeof(done));
    coud(solve(0, 0, k), 15);
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}