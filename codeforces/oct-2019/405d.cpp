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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 1e6+5;
const int S = 1000000;
bool taken[N];
int x[N/2];
bool settled[N];
vi res;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n; cin>>n; memset(settled, false, sizeof(settled)); memset(taken, false, sizeof(taken));
    int unsettled = n;
    FOR(i, 0, n) {
        cin>>x[i];
        taken[x[i]] = true;
    }

    FOR(i, 0, n) {
        if(!taken[S + 1 - x[i]]) {
            settled[i] = true;
            taken[S + 1 - x[i]] = true;
            res.push_back(S + 1 - x[i]);
            unsettled--;
        }
    }

    if(unsettled) {
        assert(unsettled % 2 == 0);

        vi goodones;
        FOR(i, 1, S+1) {
            if(!taken[i] && !taken[S + 1 - i] && i < S + 1 - i) {
                goodones.push_back(i);
            }
        }

        while(unsettled) {
            res.push_back(goodones.back());
            res.push_back(S + 1 - goodones.back());
            goodones.pop_back();
            unsettled-=2;
        }
    }

    cout<<res.size()<<endl;
    for(int r : res) cout<<r<<" ";

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}