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

const int N = 1e5+5;
int arr[N];

struct SegmentTreeNode {
	int lf, rf, maxf;

	//assign the leaf with the value.
	void assignLeaf(int value) {
		lf = rf = maxf = 1;
	}
	
	//do the merge option here.
	void merge(int lo, int hi, SegmentTreeNode& left, SegmentTreeNode& right) {
		maxf = max(left.maxf, right.maxf);
		int mid = (lo + hi) / 2;
		lf = left.lf;
		rf = right.rf;
		if(arr[mid+1] == arr[lo]) {
			lf += right.lf;
		}
		if(arr[mid] == arr[hi]) {
			rf += left.rf;
		}
		if(maxf < lf) {
			maxf = lf;
		}
		if(maxf < rf) {
			maxf = rf;
		}
		if(arr[mid]==arr[mid+1] && (left.rf + right.lf) > maxf) {
			maxf = left.rf + right.lf;
		}
	}
	
	//return the output.
	int getValue() {
		return maxf;
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
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(lo, hi, nodes[left], nodes[right]);
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
		result.merge(left, right, leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N) {
		return 4*N;	
	}
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,q,l,r;
    while(cin>>n && n) {
    	cin>>q;
    	FOR(i, 0, n) {
    		cin>>arr[i];
    	}
    	SegmentTree<int, int> st(arr, n);
		FOR(i, 0, q) {
			cin>>l>>r; l--; r--;
			cout<<st.getValue(l, r)<<endl;
		}
    }

    return 0;
}