/*
    A large part of this template has been copy-pasted. Heck i don't even know how some of these work :|
*/

#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
const int INF = 1<<29;
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
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
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

const int N = 200000+30000+10;

class nodeElement
{
public:

    bool isquery;
    int left,right,k,value,indi;

    nodeElement() {
        isquery = false;
        left = right = k = value = indi = -1;
    }
    
    void setQuery(int left, int right ,int k, int indi) {
        isquery = true;
        this -> left = left;
        this -> right = right;
        this -> k = k;
        this-> indi = indi;
        value = -1;
    }

    void setValue(int value, int indi) {
        isquery = false;
        this -> value = value;
        this -> indi = indi;
        left = -1;
        right = -1;
        k = -1;
    }

    ~nodeElement(){

    }
};

/*
    SEGTREE
*/
struct SegmentTreeNode {
    //store the properties here.
    bool value;
    int cnt;

    //assign the leaf with the value.
    void assignLeaf(bool value) {
        this -> value = value;
        if (value)
        {
            cnt=1;
        }else{
            cnt = 0;
        }
    }
    
    //do the merge option here.
    void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
        value = left.value | right.value;
        cnt = left.cnt + right.cnt;
    }
    
    //return the output.
    int getValue() {
       return cnt; 
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
            // nodes[stIndex].assignLeaf(arr[lo]);
            nodes[stIndex].assignLeaf(false);
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



bool cmp(const nodeElement a,const nodeElement b){
    int vala,valb;
    if (a.isquery)
    {
        vala = a.k;
    }else {
        vala = a.value;
    }    

    if (b.isquery)
    {
        valb = b.k;
    }else{
        valb = b.value;
    }

    if (vala != valb)
    {
        return vala>valb;
    }
    if (a.isquery)
    {
        return true;
    }
    return false;
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,ind=0;
    nodeElement arr[N];

    n = nextint();
    int temp;
    F(i, 0, n){
        temp = nextint();
        arr[ind++].setValue(temp,i);
    }

    int q,l,r,val;
    q = nextint();

    F(i, 0, q){
        l = nextint();
        r = nextint();
        val = nextint();
        arr[ind++].setQuery(l,r,val,i);
    }

    bool pres[n+5];
    memset(pres,false,sizeof(pres));
    SegmentTree<bool,int> seg(pres,n);

    sort(arr,arr+ind,cmp);

    vi ans(q);
    F(i, 0, ind) {
        if (arr[i].isquery)
        {
            ans[arr[i].indi] = seg.getValue(arr[i].left-1, arr[i].right-1);            
        } else {
            seg.update(arr[i].indi,true);
        }
    }

    F(i, 0, ans.size()){
        printf("%d\n", ans[i]);
    }

    return 0;          
}/*
    Shitty timelimit :| , cin/cout gives TLE :~(
*/