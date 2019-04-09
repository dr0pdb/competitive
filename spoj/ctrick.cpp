#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

struct SegmentTreeNode {
	//store the properties here.
	int cntz=0;

	//assign the leaf with the value.
	void assignLeaf(int value) {
		cntz = value;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		this->cntz = left.cntz + right.cntz;
	}
	
	//return the output.
	int getValue() {
		return cntz;
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
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}

	int kthZ(int k) {
		return getKthZero(1, 0, N-1, k);
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
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
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

	int getKthZero(int stIndex, int lo, int hi, int k) {
		if(lo == hi) {
			return lo;
		}

		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo)/2;
		if(nodes[left].getValue() >= k) {
			return getKthZero(left, lo, mid, k);
		}
		
		k -= nodes[left].getValue();
		return getKthZero(right, mid+1, hi, k);
	}
};

const int MAXN = 20500;
int arr[MAXN],ans[MAXN];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,pos=0,total_blanks;
    cin>>t;

    while(t--) {
    	cin>>n;
    	if(n == 1) {
    		cout<<1<<endl;
    		continue;
    	}
    	FOR(i, 0, n) arr[i]=1;
    	SegmentTree<int, int> st(arr, n);
		int pos = 1, total_blanks = n-1;
		st.update(1, 0);
		ans[1]=1;
		FOR(i, 2, n+1) {
			int bn = i;
			bn += st.getValue(0, pos); bn %= total_blanks; bn++;
			// deb(st.getValue(0, 2));
			int ind = st.kthZ(bn);
			ans[ind]=i;
			st.update(ind, 0);
			// cout<<"Updating ind: "<<ind<<" to 0\n New value between 0 and ind is "<<st.getValue(0, ind)<<endl;
			pos = ind;
			total_blanks--;
		}    	

    	FOR(i, 0, n) {
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }

    return 0;
}