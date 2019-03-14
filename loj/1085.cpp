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

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    ll sum(int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // l and r should be given as 0 based indexes.
    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    // idx as zero based.
    void add(ll idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

set<int> s;
map<int,int> m;
const int N = 1e5+5;
int arr[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;

    F(tn, 1, t+1) {
    	s.clear();
    	m.clear();

    	cin>>n;
    	F(i, 0, n) {
    		cin>>arr[i];
    		s.insert(arr[i]);
    	}

    	int cnt = 0;
    	for(auto num: s) {
    		m[num] = cnt++;
    	}

    	FenwickTree ft(n);
    	ll ans = 0;

    	F(i, 0, n) {
    		ll x = (ft.sum(m[arr[i]]-1) + 1)%MOD;
    		ans += x;
    		ans %= MOD;
    		ft.add(m[arr[i]], x);
    	}

    	cout<<"Case "<<tn<<": "<<ans<<endl;
    }

    return 0;
}/*

*/