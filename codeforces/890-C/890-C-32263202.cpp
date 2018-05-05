#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 0x3f3f3f3f
#define SIEVELIM 10000000+10
#define EPS 1e-7
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()
/*----------------------------------------------------------------------*/

const int N = 200000+5;
int n,arr[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    set<int>s;
    s.insert(0);
    
    F(i, 0, n){
    	cin>>arr[i];
    	set<int>::iterator itr = s.find(arr[i]);
    	if (itr != s.end())
    	{
    		s.erase(itr);
    	}
    	s.insert(i+1);
    }

    cout<<s.size();

    return 0;       
}