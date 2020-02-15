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

const int N = 2e5+5;
int a[N],arr[N];
vii vals;
int n;

struct SegmentTreeNode {
    int sm;

	//assign the leaf with the value.
	void assignLeaf(int value) {
		sm = value;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
        sm = left.sm + right.sm;
	}
	
	//return the output.
	int getValue() {
		return sm;
	}
};

//T is the input array type and V is the output type.
template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N; // tree size.
	
public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int pos) {
		return getValue(1, 0, N-1, pos);
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	int getValue(int stIndex, int left, int right, int pos) {
		if (left == right) {
            // assert(nodes[left].getValue() == 1);
            return left;
        }
			
		int mid = (left + right) / 2;
		if(nodes[2*stIndex].getValue() >= pos)
            return getValue(2*stIndex, left, mid, pos);
        
        return getValue(2*stIndex+1, mid + 1, right, pos - nodes[2*stIndex].getValue());
	}
	
	int getSegmentTreeSize(int N) {
		return 4*N;	
	}
	
	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

bool cmp(ii a, ii b) {
    if(a.ff != b.ff) return a.ff > b.ff;
    return a.ss < b.ss;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n; vals.resize(n);
    FOR(i, 0, n) {
        cin>>a[i];
        vals[i] = {a[i], i};
        arr[i] = 1;
    }
    sort(all(vals), cmp);
    SegmentTree<int,int> st(arr, n);
    int m; cin>>m;
    vector<tuple<int,int,int> >  reqs(m); // k, pos and idx.
    int k,pos,idx;
    FOR(i, 0, m) {
        cin>>k>>pos;
        reqs[i] = make_tuple(k, pos, i);
    }
    sort(all(reqs));
    vi res(m); int curr = n;
    RFOR(i, m - 1, 0) {
        tie(k, pos, idx) = reqs[i];
        // cout<<k<<" "<<pos<<" "<<idx<<endl;
        while(curr > k) {
            // deb(vals[curr-1].ff);
            st.update(vals[curr-1].second, 0); // delete the element
            curr--;
        }
        res[idx] = a[st.getValue(pos)];
    }
    for(int a : res) {
        cout<<a<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}