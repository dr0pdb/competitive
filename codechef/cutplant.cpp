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

const int N = 1e5+5;
int initial[N], target[N];
int tree_min[4*N],tree_max[4*N],n;

void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
        tree_min[node] = initial[a];
        tree_max[node] = target[a];
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
    
    tree_min[node] = min(tree_min[node*2], tree_min[node*2+1]);
	tree_max[node] = max(tree_max[node*2], tree_max[node*2+1]); // Init root value
}

int query_tree_min(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return INF; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree_min[node];

	int q1 = query_tree_min(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree_min(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = min(q1, q2); // Return final result
	
	return res;
}

int query_tree_max(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -INF; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree_max[node];

	int q1 = query_tree_max(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree_max(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}

bool cmp(ii a, ii b) {
    if(a.ff != b.ff) return a.ff > b.ff;
    return a.ss < b.ss;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t; 
    while(t--) {
        cin>>n;
        FOR(i, 0, n) cin>>initial[i];
        FOR(i, 0, n) cin>>target[i];

        bool impos = false;
        FOR(i, 0, n) {
            if(initial[i] < target[i]) {
                impos = true; break;
            }
        }

        if(impos) {
            cout<<-1<<endl;
            continue;
        }

        build_tree(1, 0, n-1);
        vii h(n);
        FOR(i, 0, n) {
            h[i] = {target[i], i};
        }
        sort(all(h), cmp);
        int res = 0, curr = -1;

        FOR(i, 0, n) {
            if(initial[h[i].ss] == target[h[i].ss]) continue;
            if(curr == -1 || (target[h[curr].ss] != target[h[i].ss]) 
                || (query_tree_min(1, 0, n-1, h[curr].ss, h[i].ss) < target[h[curr].ss])
                || (query_tree_max(1, 0, n-1, h[curr].ss, h[i].ss) > target[h[curr].ss])) res++;

            curr = i;
        }

        cout<<res<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}