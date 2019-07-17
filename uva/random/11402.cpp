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

const int N = 1024001;
int arr[N];

struct SegmentTreeNode {
	int bucca, lazy, lt; // lt - 0 for all to bucca, 1 for bar, and 2 for inverse.

	//assign the leaf with the value.
	void assignLeaf(int value) {
		bucca = value;
		lazy = 0;
		lt = -1;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		this->bucca = left.bucca + right.bucca;
	}
	
	//return the output.
	int getValue() {
		return bucca;
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
	
	void update(int lo, int hi, int typ) {
		update(1, 0, N-1, lo, hi, typ);
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
	
	void push(int stIndex, int l, int r) {
		if(nodes[stIndex].lazy) {
			nodes[stIndex].lazy = 0;
			int left = 2*stIndex; int right = left + 1;
			nodes[left].lazy = nodes[right].lazy = 1;
			nodes[left].lt = nodes[right].lt = nodes[stIndex].lt;
			int mid = (l + r )/ 2;
			if(nodes[stIndex].lt == 0) {
				nodes[left].bucca = (mid - l + 1);
				nodes[right].bucca = (r - mid);
			} else if(nodes[stIndex].lt == 1) {
				nodes[left].bucca = nodes[right].bucca = 0;
			} else {
				nodes[left].bucca = (mid - l + 1) - nodes[left].bucca;
				nodes[right].bucca = (r - mid) - nodes[right].bucca;
			}
		}
	}

	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		push(stIndex, left, right);
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

	void update(int stIndex, int left, int right, int lo, int hi, int lt) {
		push(stIndex, left, right);
		if (left == lo && right == hi) {
			if(lt == 0) {
				nodes[stIndex].bucca = right - left + 1;
			} else if(lt == 1) {
				nodes[stIndex].bucca = 0;
			} else {
				nodes[stIndex].bucca = (right - left + 1) - nodes[stIndex].bucca;
			}
			if(nodes[stIndex].lt == lt) {
				if(lt != 2) {
					nodes[stIndex].lazy = 1;
				} else {
					nodes[stIndex].lazy++;
					nodes[stIndex].lazy %= 2;
				}
			} else {
				nodes[stIndex].lazy = 1;
				nodes[stIndex].lt = lt;	
			}
			return;
		}

		int mid = (left + right) / 2;
		if(hi  > mid) {
			update(2*stIndex+1, mid + 1, right, max(mid+1, lo), min(hi, right), lt);
		}
		if(lo <= mid) {
			update(2*stIndex, left, mid, max(left, lo), min(mid, hi), lt);
		}
		nodes[stIndex].merge(nodes[2*stIndex], nodes[2*stIndex+1]);
	}
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,ind,cnt,m,q,a,b;
    cin>>t;
    string s;
    char tp;

    FOR(tn, 1, t+1) {
    	cout<<"Case "<<tn<<":\n";
    	ind = 0;
    	cin>>m;
    	FOR(i, 0, m) {
    		cin>>cnt>>s;
    		FOR(j, 0, cnt) {
    			for(char c : s) {
    				arr[ind++] = c - '0';
    			}
    		}
    	}
    	SegmentTree<int, int> st(arr, ind);
    	cin>>q;
    	FOR(i, 0, q) {
    		cin>>tp>>a>>b;
    		if(tp == 'F') {
    			st.update(a, b, 0);
    		} else if (tp == 'E') {
    			st.update(a, b, 1);
    		} else if(tp == 'I') {
    			st.update(a, b, 2);
    		} else {
				cout<<st.getValue(a, b)<<endl;;
    		}
    	}
    }

    return 0;
}