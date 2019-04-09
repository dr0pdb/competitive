#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define xN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define yX(a,b) (a)>(b)?(a):(b)
#define xN2(a,b) (a)<(b)?(a):(b)
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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,k,a,b,x=(1LL<<15),y=-1;
    cin>>n>>k>>a>>b;

    FOR(i, 0, n) {
    	ll l1=abs(i*k-(b+a+k)%k);
		ll l2=abs(i*k+(b-a+k)%k);
		ll l3=abs(i*k-(b-a+k)%k);
		ll l4=abs(i*k+(b+a+k)%k);
		x=min(x,(n*k)/__gcd(l1,n*k));
		y=max(y,(n*k)/__gcd(l1,n*k));

		x=min(x,(n*k)/__gcd(l2,n*k));
		y=max(y,(n*k)/__gcd(l2,n*k));

		x=min(x,(n*k)/__gcd(l3,n*k));
		y=max(y,(n*k)/__gcd(l3,n*k));

		x=min(x,(n*k)/__gcd(l4,n*k));
		y=max(y,(n*k)/__gcd(l4,n*k));
    }
    cout<<x<<" "<<y;

    return 0;
}