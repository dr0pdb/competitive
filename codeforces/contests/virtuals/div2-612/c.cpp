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

int n;
vi arr;
int sm;
int dp[101][101][101][2];

// p - odd, q - even
int solve(int idx, int p, int q, int last) {
    if(idx == n) return 0;
    int &ret = dp[idx][p][q][last];
    if(ret >= 0) return ret;
    ret = INF;

    if(arr[idx] == 0) {
        if(p) {
            int cnt = (idx > 0 && last != 1);
            ret = min(ret, cnt + solve(idx + 1, p - 1, q, 1));
        }
        if(q) {
            int cnt = (idx > 0 && last != 0);
            ret = min(ret, cnt + solve(idx + 1, p, q - 1, 0));
        }
    } else {
        int cnt = (idx > 0) & ((arr[idx]%2) != last);
        ret = cnt + solve(idx + 1, p, q, arr[idx]%2);
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n;
    arr.resize(n);
    vi pres(n + 1);
    FOR(i, 0, n) {
        cin>>arr[i];
        pres[arr[i]] = true;
    }
    int p = 0, q = 0;
    FOR(i, 1, n + 1) {
        if(!pres[i]) {
            if(i % 2) {
                p++;
            } else q++;
        }
    }
    sm = p + q;
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, p, q, 0);
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}