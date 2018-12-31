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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000009;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x << endl; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/

const int MAXN = 200005;
ll n,k,q;
ll pts[MAXN][6];

ll dist(int i, int j) {
	ll ret = 0;
	F(v, 0, k) {
		ret += abs(pts[i][v] - pts[j][v]);
	}

	return ret;
}

struct SegmentTreeNode {
	//store the properties here.
	pair<ll,ll> data;

	//assign the leaf with the value.
	void assignLeaf(pair<ll,ll> value) {
		data = value;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		pair<ll,ll> best; ll bdist = -1,dit;

		dit = dist(left.data.first, left.data.second);
		if(dit > bdist) {
			bdist = dit;
			best = left.data;
		}

		dit = dist(left.data.first, right.data.first);
		if(dit > bdist) {
			bdist = dit;
			best = {left.data.first, right.data.first};
		}

		dit = dist(left.data.first, right.data.second);
		if(dit > bdist) {
			bdist = dit;
			best = {left.data.first, right.data.second};
		}

		dit = dist(left.data.second, right.data.first);
		if(dit > bdist) {
			bdist = dit;
			best = {left.data.second, right.data.first};
		}

		dit = dist(left.data.second, right.data.second);
		if(dit > bdist) {
			bdist = dit;
			best = {left.data.second, right.data.second};
		}

		dit = dist(right.data.first, right.data.second);
		if(dit > bdist) {
			bdist = dit;
			best = right.data;
		}

		data = best;
	}
	
	//return the output.
	ll getValue() {
		return dist(data.first, data.second);
	}
};

//T is the input array type and V is the output type.
template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N; // tree size.
	
public:
	SegmentTree(int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index) {
		update(1, 0, N-1, index);
	}
	
private:	
	void buildTree(int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(ii(lo, lo));
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		buildTree(left, lo, mid);
		buildTree(right, mid + 1, hi);
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
	
	void update(int stIndex, int lo, int hi, int index) {
		if (lo == hi) {
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		if (index <= mid)
			update(left, lo, mid, index);
		else
			update(right, mid+1, hi, index);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};


int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>k;
    F(i, 0, n) {
    	F(j, 0, k) {
    		cin>>pts[i][j];
    	}
    }

    SegmentTree<pair<ll,ll>, ll> seg(n);
    cin>>q;
    int t,l,r;
    while(q--) {
    	cin>>t;
    	if(t == 1) {
    		cin>>l; l--;
    		F(i, 0, k) {
    			cin>>pts[l][i];
    		}
    		seg.update(l);
    	} else {
    		cin>>l>>r; l--; r--;
    		cout<<seg.getValue(l, r)<<endl;
    	}
    }

    return 0;          
}/*
    
*/
 