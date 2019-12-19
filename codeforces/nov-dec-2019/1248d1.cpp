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
string s;

int beauty() {
    int res = 1, minm = INF, minc = 0, cnt = 0;
    FOR(i, 0, n) {
        if(s[i] == '(') cnt++;
        else cnt--;    
        if(minm > cnt) {
            minm = cnt;
            minc = 1;
        } else if(minm == cnt) minc++;
    }
    res = max(res, minc);
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>s;
    int res = 0;
    ii swaps = {1, 1};
    int op = 0;
    FOR(i, 0, n) {
        if(s[i] == '(') op++;
        else op--;
    }
    // deb(op);
    if(!op) {
        res = beauty();

        FOR(i, 0, n) {
            FOR(j, i + 1, n) {
                swap(s[i], s[j]);
                int tmp = beauty();
                if(tmp > res) {
                    res = tmp;
                    swaps = {i + 1, j + 1};
                }
                swap(s[i], s[j]);
            }
        }   
    }
    cout<<res<<endl<<swaps.ff<<" "<<swaps.ss<<endl;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}