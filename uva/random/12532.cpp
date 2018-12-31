#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int MN = 1e5+5;
int n,k;
char arr[MN];

// void build(int ti, int lo, int hi) {
// 	if(lo == hi) {
// 		tree[ti] = arr[lo];
// 		return;
// 	}

// 	int mid = lo + (hi - lo)/2;
// 	build(2*ti, lo, mid);
// 	build(2*ti + 1, mid+1, hi);
// 	tree[ti] = tree[2*ti] * tree[2*ti+1];
// }

// int get(int ti, int lo, int hi, int ql, int qr) {
// 	if (ql > qr)
//         return 1;
    
//     if (ql == lo && qr == hi) {
//         return tree[ti];
//     }

// 	int mid = lo + (hi - lo)/2;
// 	return get(2*ti, lo, mid, ql, min(qr, mid)) * get(2*ti+1, mid+1, hi, max(ql, mid+1), qr);
// }

// void update(int ti, int updateindex, int lo, int hi) {
// 	if(lo == hi) {
// 		tree[ti] = arr[updateindex];
// 		return;
// 	}

// 	int mid = lo + (hi - lo)/2;
// 	if(updateindex <= mid) {
// 		update(2*ti, updateindex, lo, mid);
// 	} else {
// 		update(2*ti+1, updateindex, mid+1, hi);
// 	}

// 	tree[ti] = tree[2*ti] * tree[2*ti + 1];
// }

struct SegmentTreeNode {
	//store the properties here.
	char val='+';

	//assign the leaf with the value.
	void assignLeaf(char value) {
		val = value;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		if(left.val == '0' || right.val == '0') {
			val = '0';
		} else if(left.val == right.val) {
			val = '+'; 
		} else {
			val = '-';
		}
	}
	
	//return the output.
	char getValue() {
		return val;
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
};


int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    while(cin>>n>>k) {
    	int val;
	 	F(i, 0, n) {
	 		cin>>val;
    		if(val == 0) {
    			arr[i] = '0';
    		} else if(val > 0) {
    			arr[i] = '+';
    		} else {
    			arr[i] = '-';
    		}
    	}

    	SegmentTree<char, char> st(arr, n);

    	char t;
    	int a,b;
    	F(i, 0, k) {
    		cin>>t>>a>>b;
    		if (t == 'C')
    		{
    			// arr[a-1]=b;
    			char tmp = '0';
    			if(b > 0) {
    				tmp = '+';
    			} else if (b < 0) {
    				tmp = '-';
    			}
    			st.update(a-1, tmp);
    			// update(1, a-1, 0, n-1);	
    		} else {
    			cout<<st.getValue(a-1, b-1);
    		}
    	}
    	cout<<endl;
    }

    return 0;
}/*

*/
