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
string s,t;
int leftmost[N], rightmost[N],n,m, res; // leftmost[i] : leftmost idx of s s.t. t[0 : i] is subsequence of s[0 : leftmost[i]]

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>s>>t; n = s.size(); m = t.size();
    res = INT_MIN;
    int tidx = 0;

    FOR(i, 0, n) {
        if(s[i] == t[tidx]) {
            leftmost[tidx] = i;
            tidx++;
        }

        if(tidx == m) {
            res = max(res, n - (int)i - 1);
            break;
        }
    }

    tidx = m - 1;
    RFOR(i, n - 1, 0) {
        if(s[i] == t[tidx]) {
            rightmost[tidx] = i;
            tidx--;
        }

        if(tidx == -1) {
            res = max(res, (int)i);
            break;
        }
    }

    FOR(i, 0, m - 1) {
        res = max(res, rightmost[i + 1] - leftmost[i] - 1);
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}