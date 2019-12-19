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

const int N = 105;
int b,d;
string a,c;
int cnt[N], pos[N]; 
// instead of counting the number of a's per c, do the opposite.(gives TLE on test 38)
// For every position of C, figure out how many complete C's and the final position it will go when it goes through one complete A. 

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>b>>d>>a>>c;
    int an = a.size(), cn = c.size();

    FOR(i, 0, cn) {
        int idx = i;
        FOR(j, 0, an) {
            if(a[j] == c[idx]) idx++;
            if(idx == cn) cnt[i]++, idx = 0; 
        }
        pos[i] = idx;
    }

    int ans = 0, curr = 0;
    FOR(i, 0, b) {
        ans += cnt[curr];
        curr = pos[curr];
    }
    cout<<ans/d;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}