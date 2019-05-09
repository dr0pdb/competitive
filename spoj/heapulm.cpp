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

const int N = 50001;
int n;
pair<string,int> arr[N];
int arr2[N];

struct SegmentTreeNode {
	int maxm, maxi;

	//assign the leaf with the value.
	void assignLeaf(int value, int idx) {
		maxm = value;
		maxi = idx;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		if(left.maxm >= right.maxm) {
			maxm = left.maxm;
			maxi = left.maxi;
		} else {
			maxm = right.maxm;
			maxi = right.maxi;
		}
	}
	
	//return the output.
	int getValue() {
		return maxi;
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
			nodes[stIndex].assignLeaf(arr[lo], lo);
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
};

void recurse(SegmentTree<int, int> &st, int lo, int hi) {
	if(lo > hi) return;
	if(lo == hi) {
		cout<<"("<<arr[lo].ff<<"/"<<arr[hi].ss<<")";
		return;
	}

	int maxmi = st.getValue(lo, hi);
	cout<<"(";
	recurse(st, lo, maxmi-1);
	cout<<arr[maxmi].ff<<"/"<<arr[maxmi].ss;
	recurse(st, maxmi+1, hi);
	cout<<")";
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    while(cin>>n && n) {
    	FOR(i, 0, n) {
    		cin>>s;
    		int tmp = 0, val;
    		FOR(j, 0, s.size()) {
    			if(s[j] == '/') break;
				tmp++;
    		}
    		int sz = s.size();
   			sz -= tmp + 1;
    		val = stoi(s.substr(tmp + 1, sz));
    		arr[i] = {s.substr(0, tmp), val};
    	}

    	sort(arr, arr+n);
    	FOR(i, 0, n) arr2[i] = arr[i].ss;
    	SegmentTree<int, int> st(arr2, n);
    	recurse(st, 0, n-1);
    	cout<<endl;
    }

    return 0;
}