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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int lim[4], tot = 0;
    set<int> ss;
    FOR(i, 0, 4) {
        cin>>lim[i];
        if(lim[i]) ss.insert(i);
        tot += lim[i];
    }

    for(int start : ss) {
        vi res = {start};
        int cnt[4] = {0}; 
        cnt[start] = 1;
        bool good = true;
        FOR(i, 1, tot) {
            int lo = res.back() - 1;
            int hi = res.back() + 1;
            if(lo >= 0 && cnt[lo] < lim[lo]) {
                cnt[lo]++;
                res.push_back(lo);
            } else if(hi <= 3 && cnt[hi] < lim[hi]) {
                res.push_back(hi);
                cnt[hi]++;
            } else {
                good = false;
                break;
            }
        }
        if(good) {
            cout<<"YES\n";
            for(int a : res) {
                cout<<a<<" ";
            }
            return 0;
        }
    }
    cout<<"NO";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}