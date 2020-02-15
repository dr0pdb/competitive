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

const int nax = 101;
int n,k, perm[nax], target[nax], curr[nax];

void init() {
    FOR(i, 1, n + 1) curr[i] = i;
}

void apply_perm_forward() {
    vi tmp(n+1);
    FOR(i, 1, n + 1) {
        tmp[i] = curr[perm[i]];
    }
    FOR(i, 1, n + 1) {
        curr[i] = tmp[i];
    }
}

void apply_perm_backward() {
    vi tmp(n+1);
    FOR(i, 1, n + 1) {
        tmp[perm[i]] = curr[i];
    }
    FOR(i, 1, n + 1) {
        curr[i] = tmp[i];
    }
}

bool eq() {
    FOR(i, 1, n + 1) {
        if(curr[i] != target[i]) return false;
    }
    return true;
}

void special_case() {
    apply_perm_forward();
    if(!eq()) return;
    init();
    apply_perm_backward();
    if(!eq()) return;
    cout << (k == 1 ? "YES" : "NO");
    exit(0);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>k;
    FOR(i, 1, n + 1) cin>>perm[i];
    FOR(i, 1, n + 1) cin>>target[i];
    init();
    if(is_sorted(target + 1, target + n + 1)) {
        cout<<"NO";
        return 0;
    }
    special_case();
    init();
    int forward_steps = 0;
    while(true) {
        if(eq()) break;
        forward_steps++;
        apply_perm_forward();
        if(forward_steps > k) break; 
    }
    if(forward_steps <= k && (forward_steps - k)%2 == 0) {
        cout<<"YES";
        return 0;
    }
    int backward_steps = 0;
    init();
    while(true) {
        if(eq()) break;
        backward_steps++;
        apply_perm_backward();
        if(backward_steps > k) break;
    }
    if(backward_steps <= k && (backward_steps - k )%2 == 0) {
        cout<<"YES";
        return 0;
    }
    
    cout<<"NO";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}