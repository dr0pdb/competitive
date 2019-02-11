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

const int N = 2e5+1;
map<ll,ll> m;
ll l[N],r[N];
ll cnt[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;

    F(i, 0, n) {
    	cin>>l[i]>>r[i];
    	m[l[i]]++;
    	m[r[i]+1]--;
    }

    if(n == 1) {
    	cout<<r[0]-l[0]+1;
    	return 0;
    }

    memset(cnt, 0, sizeof(cnt));

    // for(auto itr = m.begin(); itr != m.end(); ++itr) {
    // 	cout<<itr->first<<" "<<itr->second<<endl;
    // }

    ll cum = 0;
    auto prev = m.begin(), itr = m.begin(); ++itr;
    cum += prev->second;
    for(; itr != m.end(); ++itr) {
    	ll sz = (ll)itr->first - (ll)prev->first;
    	// deb(cum); deb(sz);
    	cnt[cum] += sz;
    	cum += itr->second;
    	++prev;
    }

    F(i, 1, n+1) {
    	cout<<cnt[i]<<" ";
    }

    return 0;
}/*

*/