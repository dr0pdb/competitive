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

const int N = 1e6+1;
string arr;
int balanced[4*N], lopen[4*N], ropen[4*N];

void merge(int node) {
    int l = 2*node, r = 2*node + 1;
    int x = min(lopen[l], ropen[r]);
    balanced[node] = balanced[l] + balanced[r] + x;
    lopen[node] = lopen[l] + lopen[r] - x;
    ropen[node] = ropen[l] + ropen[r] - x;
}

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	balanced[node] = 0;
        lopen[node] = (arr[a] == '(');
        ropen[node] = (arr[a] == ')');
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	merge(node);
}

iii query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return {0, {0, 0}}; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return {balanced[node], {lopen[node], ropen[node]}};

	iii q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	iii q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    iii res;
    int x = min(q1.ss.ff, q2.ss.ss);
    res.ff = q1.ff + q2.ff + x;
    res.ss.ff = q1.ss.ff + q2.ss.ff - x;
    res.ss.ss = q1.ss.ss + q2.ss.ss - x;
    return res;
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>arr;
    int n = arr.size();
    build_tree(1, 0, n-1);
    int m,l,r; cin>>m;
    while(m--) {
        cin>>l>>r; l--; r--;
        cout<<2*query_tree(1, 0, n - 1, l, r).ff<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}