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

const int N = 2e5+5;
int arr[N];

struct SegmentTreeNode {
	//store the properties here.
    int val, cnt;

	//assign the leaf with the value.
	void assignLeaf(int value) {
		val = value;
        cnt = 1;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
        cnt = left.cnt + right.cnt; // val irrelevant.
	}
	
	//return the output.
	ii getValue() {
		return {val, cnt}; 
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
	
	V getValue(int lo, int hi, int idx) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi, idx);
		return result.getValue();
	}
	
	void update(int index) {
		update(1, 0, N-1, index);
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
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi, int idx) {
		if (lo == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;

        if(nodes[2*stIndex].cnt >= idx) {
            return getValue(2*stIndex, left, mid, lo, mid, idx);
        }
		
        return getValue(2*stIndex+1, mid+1, right, mid+1, hi, idx - nodes[2*stIndex].cnt);
	}
	
	int getSegmentTreeSize(int N) {
		return 4*N;	
	}
	
	void update(int stIndex, int lo, int hi, int index) {
		if (lo == hi) {
			nodes[stIndex].cnt = 0;
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		if (index <= nodes[left].cnt)
			update(left, lo, mid, index);
		else
			update(right, mid+1, hi, index - nodes[left].cnt);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    int n; cin>>n;
    FOR(i, 0, n) cin>>arr[i];
    SegmentTree<int,ii> st(arr, n);
    int q;
    FOR(i, 0, n) {
        cin>>q;
        cout<<st.getValue(0, n-1, q).first<<" ";
        st.update(q);
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}