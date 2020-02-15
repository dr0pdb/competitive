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

const int nax = 1e5+5;
ll n,k;
ll arr[nax];

bool can(ll rounds) {
    ll sm = 0;
    FOR(i, 0, n) {
        sm += min(arr[i], rounds);
    }
    return sm < k;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    ll sm = 0;
    cin>>n>>k;
    FOR(i, 0, n) {
        cin>>arr[i];
        sm += arr[i];
    }
    if(sm < k) {
        cout<<-1;
        return 0;
    }
    ll lo = 0, hi = *max_element(arr, arr + n), comprounds = 0;
    while(lo <= hi) {
        ll mid = (lo + hi)>>1;
        if(can(mid)) {
            comprounds = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }
    FOR(i, 0, n) {
        k -= min(arr[i], comprounds);
        arr[i] -= comprounds;
    }
    FOR(i, 0, n) {
        if(arr[i] > 0 && k) {
            arr[i]--;
            k--;
        }
        if(k == 0) {
            FOR(j, i + 1, n) {
                if(arr[j] > 0) cout<<j + 1<<" ";
            }
            FOR(j, 0, i + 1) {
                if(arr[j] > 0) cout<<j + 1<<" ";
            }

            return 0;
        }
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}