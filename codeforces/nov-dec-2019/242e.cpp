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

int arr[N],n;
int tree[4*N][20][2]; // no of elements with bit is 0 and 1 respectively.
int lazy[4*N][20]; // number of swaps of bit i.
bool hasLazy[4*N];

void merge(int node) {
    int l = node * 2; int r = l + 1;
    FOR(i, 0, 20) {
        tree[node][i][0] = tree[l][i][0] + tree[r][i][0];
        tree[node][i][1] = tree[l][i][1] + tree[r][i][1];
    }
}

void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    	FOR(i, 0, 20) {
            if(arr[a] & (1 << i)) {
                tree[node][i][1] = 1;
            } else {
                tree[node][i][0] = 1;
            }
        }
        return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	merge(node);
}

void update_tree(int node, int a, int b, int i, int j, int value) {
  
  	if(hasLazy[node]) {
        FOR(i, 0, 20) {
            if(lazy[node][i]) {
                swap(tree[node][i][0], tree[node][i][1]);
            }
        }

		if(a != b) {
            FOR(i, 0, 20) {
                lazy[node*2][i] += lazy[node][i]; lazy[2*node][i] %= 2; if(lazy[2*node][i]) hasLazy[2*node] = true;
    		    lazy[node*2+1][i] += lazy[node][i]; lazy[2*node+1][i] %= 2; if(lazy[2*node+1][i]) hasLazy[2*node+1] = true;
            }
		}

        memset(lazy[node], 0, sizeof(lazy[node]));
   		hasLazy[node] = false;
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
        FOR(i, 0, 20) {
            if(value & (1 << i)) {
                swap(tree[node][i][0], tree[node][i][1]);
            }
        }

		if(a != b) {
            FOR(i, 0, 20) {
                if(value & (1 << i)) {
                    lazy[2*node][i] = 1 - lazy[2*node][i]; if(lazy[2*node][i]) hasLazy[2*node] = true;
                    lazy[2*node+1][i] = 1 - lazy[2*node+1][i]; if(lazy[2*node+1][i]) hasLazy[2*node+1] = true;
                }
            }
		}

        return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	merge(node);
}

ll query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range

	if(hasLazy[node]) { // This node needs to be updated
		FOR(i, 0, 20) {
            if(lazy[node][i]) {
                swap(tree[node][i][0], tree[node][i][1]);
            }
        }

		if(a != b) {
            FOR(i, 0, 20) {
                lazy[node*2][i] += lazy[node][i]; lazy[2*node][i] %= 2; if(lazy[2*node][i]) hasLazy[2*node] = true;
    		    lazy[node*2+1][i] += lazy[node][i]; lazy[2*node+1][i] %= 2; if(lazy[2*node+1][i]) hasLazy[2*node+1] = true;
            }
		}

		hasLazy[node] = false;
        memset(lazy[node], 0, sizeof(lazy[node]));
	}

	if(a >= i && b <= j) {
        ll ret = 0;
        FOR(i, 0, 20) {
            ret += (1LL << i) * 1LL * tree[node][i][1];
        }
        return ret;
    }

	ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = q1 + q2;
	
	return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    memset(tree, 0, sizeof(tree)); memset(lazy, 0, sizeof(lazy)); memset(hasLazy, false, sizeof(hasLazy));
    cin>>n;
    FOR(i, 0, n) cin>>arr[i];
    build_tree(1, 0, n-1);
    int m,t,l,r,x; cin>>m;
    while(m--) {
        cin>>t>>l>>r; l--; r--;
        if(t == 1) {
            cout<<query_tree(1, 0, n-1, l, r)<<endl;
        } else {
            cin>>x;
            update_tree(1, 0, n-1, l, r, x);
        }
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}