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

const ll N = 6e4+5;
ll n,k,segsize;
int arr[N];

struct node {

	//properties stored in a single node.
	int ans;
    bool neutral;

	//default constructor
	node(){
	   neutral = true;
    }
	
	//construct node with values.
	node(int ands){
       ans = ands;
       neutral = false;
    }
    
	//Write the merge/join operation here.
	void combine(node left, node right){
        neutral = false;
        if (left.neutral)
        {
            ans = right.ans;
            return;
        }

        if (right.neutral)
        {
            ans = left.ans;
            return;
        }
		ans = left.ans & right.ans;
	}

}st[4*N];

/*
	p is the current index of the segment tree.
	l - r is the range of the array that has been stored at the current index p of the segment tree.
*/
//call build(1,0,n-1)
void build(ll p , ll l ,ll r){
	if (l == r)
	{
		st[p] = arr[l];
		return;
	}
	
	ll middle = mid(l,r);
	build(leftChild(p),l,middle);
	build(rightChild(p),middle+1,r);
	st[p] = node();
	st[p].combine(st[leftChild(p)],st[rightChild(p)]);
}

// l and r define the current segment we are looking at and i-j is the range asked.
//call query(1,0,n-1,i,j)
node query(ll p ,ll l, ll r, ll i,ll j){
	if (i > r || j < l) {
		//return a neutral node here(eg for sum query return zero node)
		node n = node();
		return n;	
	}  
	if (l >= i && r <= j) return st[p];
	
	ll middle = mid(l,r);
	node p1 = query(leftChild(p), l, middle, i, j);
	node p2 = query(rightChild(p), middle+1,r, i, j);
	node sum = node();
	sum.combine(p1, p2);
	return sum;
}

//sets the value at pos to the new_val
// call update(1,0,n-1,pos,new_val)
// void update(ll p, ll l, ll r, ll pos, ll new_val){
// 	if(l==r){
// 		st[p] = new_val;
// 	}else {
// 		ll middle = mid(l,r);
// 		if(pos <= middle){
// 			update(leftChild(p),l,middle,pos,new_val);
// 		} else {
// 			update(rightChild(p),middle+1,r,pos,new_val);
// 		}
// 		st[p] = node();
// 		st[p].combine(st[leftChild(p)],st[rightChild(p)]);
// 	}
// }

// void binarySearchOnTree(ll p,ll l, ll r, ll value){
//     if (l==r)
//     {
//         if ((st[p].unused == k) && value)
//         {
//             usedCounter++;
//         }
//         st[p].unused -= value;
//         st[p].maxm -= value;
//         return;
//     }

//     ll middle = mid(l, r);
//     if (st[leftChild(p)].maxm >=value)
//     {
//         binarySearchOnTree(leftChild(p),l,middle,value);
//     }else {
//         binarySearchOnTree(rightChild(p),middle+1,r,value);
//     }
//     st[p].combine(st[leftChild(p)], st[rightChild(p)]); 
// }

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        cin>>n;
        cin>>k;

        if (n <= (2*k+1))
        {
            int ans,element;
            F(i, 0, n){
                cin>>element;
                if (!i)
                {
                    ans = element;
                }
                ans &= element;
            }
            F(i, 0, n){
                if (i)
                {
                    cout<<" ";
                }
                cout<<ans;
            }
            cout<<endl;
        }else{
            F(i, 0, n){
                cin>>arr[i];
                arr[n+i] = arr[i];
                arr[2*n+i] = arr[i];
            }
            segsize = 3LL*n;
            build(1,0,segsize-1);
            F(i, 0, n){
                if (i)
                {
                    cout<<" ";
                }
                cout<<query(1,0,segsize-1,n+i-k,n+i+k).ans;
            }
            cout<<endl;
        }

    }
    
	return 0;    	   
}/*
    That was tough :~|
*/