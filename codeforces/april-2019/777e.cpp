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

const int N = 1e5+5;
iii rings[N];

map<int, int> m;
int cnt = 0;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    ll maxm(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret = max(ret, bit[idx]);
        return ret;
    }

    // idx as zero based.
    void update(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] = max(bit[idx], delta);
    }
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,a,b,c;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>a>>b>>c;
    	rings[i] = {b, {a, c}};
   		m[a]= m[b] = 1;
    }

    for(auto &itr: m) {
    	itr.ss = ++cnt;
    }

    FOR(i, 0, n) {
    	rings[i].ff = m[rings[i].ff];
    	rings[i].ss.ff = m[rings[i].ss.ff];
    }

    sort(rings, rings+n);
    reverse(rings, rings+n);
    FenwickTree ft(cnt + 5);
    
    ll ans = 0;
    FOR(i, 0, n) {
    	ll curr = ft.maxm(rings[i].ff-1) + rings[i].ss.ss;
    	ans = max(ans, curr);
    	ft.update(rings[i].ss.ff, curr);
    }
    cout<<ans;

    return 0;
}