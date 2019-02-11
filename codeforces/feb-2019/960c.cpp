#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

vll p2s,ans;

int getIndex(const std::vector<ll>& V, ll val)
{
    auto iter = std::upper_bound(V.begin(), V.end(), val);
    if (iter != V.begin())
       return std::distance(V.begin(), std::prev(iter));

    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x,d,n=0;
    cin>>x>>d;

    ll curr = 2LL;
    while(curr <= x) {
    	p2s.push_back(curr-1);
    	curr *= 2LL;
    }

    curr = 1;
	while(x > 0) {
		int index = getIndex(p2s, x);
		x -= ((1<<(index+1))-1);
		F(i, 0, index+1) {
			ans.push_back(curr);
		}
		curr += d;
	}

	cout<<ans.size()<<endl;
	F(i, 0, ans.size()) {
		if(i) cout<<" ";
		cout<<ans[i];
	}

    return 0;
}/*

*/