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

const int nax = 1001;
long double dp[nax][nax][2];
bool done[nax][nax][2];

// princess - 0.
long double solve(int w, int b, int turn) {
    if(w < 0 || b < 0) return 0;
    if(done[w][b][turn]) return dp[w][b][turn];
    if(!w) return 0; // no one draws white hence dragon wins.
    if (!b)
    {
        return (turn == 0); // person with turn wins.
    }
    done[w][b][turn] = true;
    long double res = 0;

    // draw white
    res = w * 1.0 / (b + w) * (turn == 0);

    // draw black
    if(turn == 0) {
        res += b * 1.0 / (b + w) * solve(w, b - 1, 1 - turn);
    } else {
        long double fact = b * 1.0 / (b + w);
        res += fact * (w * 1.0 / (b + w - 1) * solve(w - 1, b - 1, 1 - turn)); // white jumps out.
        if(b >= 2) res += fact * ((b - 1) * 1.0 / (b + w - 1) * solve(w, b - 2, 1 - turn)); // black jumps out.
    }

    return dp[w][b][turn] = res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    int w,b;
    cin>>w>>b;
    memset(done, false, sizeof(done));
    coud(solve(w, b, 0), 9);    
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}