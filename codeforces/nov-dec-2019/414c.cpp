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

const int NN = (1 << 21) + 10;
const int N = 22;
int arr[NN],n;
ll le[NN], ri[NN], sumleft[N], sumright[N], res = 0;

void build(int v, int l, int r, int depth) {
    if(l == r) return;

    int mid = (l + r) >> 1;
    build(2*v, l, mid, depth - 1);
    build(2*v + 1, mid + 1, r, depth - 1);

    le[v] = ri[v] = 0;
    int L = (r - l + 1) >> 1;
 
	for (int i = l; i <= mid; ++i) {
		int pos = upper_bound(arr + mid + 1, arr + r + 1, arr[i]) - (arr + mid + 1);
		ri[v] += (ll)L - pos;
	}
 
	for (int i = mid + 1; i <= r; ++i) {
		int pos = upper_bound(arr + l, arr + mid + 1, arr[i]) - (arr + l);
		le[v] += (ll)L - pos;
	}

    sumleft[depth] += le[v];
    sumright[depth] += ri[v];
    res += le[v];

    sort(arr + l, arr + r + 1);
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    
    scanf("%d", &n);
    FOR(i, 0, (1 << n)) {
        scanf("%d", &arr[i]);
    }

    build(1, 0, (1 << n) - 1, n);
    int m,q; cin>>m; 
    while(m--) {
        scanf("%d", &q);

        RFOR(depth, q, 0) {
            res -= sumleft[depth];
            res += sumright[depth];
            swap(sumleft[depth], sumright[depth]);
        }

        printf("%I64d\n", res);
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}