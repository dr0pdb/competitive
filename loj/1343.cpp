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
const ll MOD = (1LL << 32);
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

struct FenwickTree2D {
    vector<vector<ll>> bit;
    ll n, m;

    FenwickTree2D(ll n, ll m) {
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(n + 1, vector<ll> (m + 1, 0));
    }

    // x and y as zero based index.
    ll sum(ll x, ll y) {
        ll ret = 0;
        for (ll i = x+1; i > 0; i -= i & (-i))
            for (ll j = y+1; j > 0; j -= j & (-j)) {
                ret += bit[i][j];
                ret %= MOD;
            }
        return ret;
    }

    // x and y as zero based index.
    void add(ll x, ll y, ll delta) {
        for (ll i = x+1; i < n; i += i & (-i))
            for (ll j = y+1; j < m; j += j & (-j)) {
                bit[i][j] += delta;
                bit[i][j] %= MOD;
            }
    }
};

const int N = 505;
int arr[N];
iii sums[250001];

bool cmp(iii a, iii b) {
	if(a.first != b.first) return a.first < b.first;
	int fr = a.second.second - a.second.first;
	int sr = b.second.second - b.second.first;

	return fr > sr;
}

ll query(FenwickTree2D &ft, ll l, ll r) {
	if (l == r-1) return 0;
	int x1 = l, y1 = l, x2 = r-1, y2 = r-1;
	return ((MOD + ((MOD + ((ft.sum(x2, y2) + ft.sum(x1, y1)) % MOD) - ft.sum(x2, y1)) % MOD) - ft.sum(x1, y2)) % MOD);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n;
    cin>>t;

    F(tn, 1, t+1) {
    	cin>>n;
    	
    	F(i, 0, n) {
    		cin>>arr[i];
    	}

    	int cnt = 0;
    	F(i, 0, n) {
    		F(j, i+1, n) {
    			sums[cnt].first=arr[i]+arr[j];
    			sums[cnt].second = {i+1, j+1};
    			cnt++;
    		}
    	}

    	sort(sums, sums+cnt, cmp);
    	FenwickTree2D ft(501,501);

    	ll ans = 0;
    	F(i, 0, cnt) {
			ll delta = (query(ft, sums[i].second.first, sums[i].second.second) + 1LL)%MOD;
    		ans += delta;
    		ans %= MOD;
    		ft.add(sums[i].second.first, sums[i].second.second, delta);
    	}

    	cout<<"Case "<<tn<<": "<<ans<<endl;
    }

    return 0;
}/*

*/