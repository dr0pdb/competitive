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

const int N = 5e5+5;
iii parts[N];

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, INF);
    }

    // l and r should be given as 0 based indexes.
    int minm(int idx) {
        int ret = INF;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret = min(ret, bit[idx]);
        return ret;
    }

    // idx as zero based.
    void update(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] = min(bit[idx], val);
    }
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,tmp;
    cin>>n;

    FOR(j, 0, 3) {
    	FOR(i, 0, n) {
    		cin>>tmp; tmp--;
    		if(j == 0) {
    			parts[tmp].ff = i;
    		} else if (j == 1) {
    			parts[tmp].ss.ff = i;
    		} else {
    			parts[tmp].ss.ss = i;
    		}
		}
    }

    sort(parts, parts + n);
    FenwickTree ft(n);
    int ans = n;
    FOR(i, 0, n) {
    	int mn = ft.minm(parts[i].ss.ff);
    	if(parts[i].ss.ss > mn) ans--;
    	ft.update(parts[i].ss.ff, parts[i].ss.ss);
    }
    cout<<ans;

    return 0;
}