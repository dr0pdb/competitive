/**
    __author__ : srv_twry
**/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}

bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& x) { return le(x, 0) ? eq(x, 0) ? 0 : -1 : 1; }
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vi arr;
    int prev = 0;
    FOR(i, 1, s.size()) {
    	if(s[i] != s[i-1]) {
    		arr.push_back(i-prev);
    		prev = i;
    	}
    }
    arr.push_back(n-prev);
    // debug_vi(arr); cout<<endl;
    int maxsz = 2 * k + 1, lo = 0, sm = 0, ans = 0, best = 0;
    FOR(i, 0, min((int)arr.size(), maxsz)) {
    	sm += arr[i];
    }
    best = sm;
    int hi = min((int)arr.size(), maxsz) - 1;
    int idx = hi + 1;
    while(idx < min((int) arr.size(), maxsz)) {
    	sm += arr[idx];
    	sm -= arr[idx - maxsz];
    	if(sm > best) {
    		best = sm;
    		lo = idx - maxsz + 1;
    		hi = idx;
    	}
    	idx++;
    }
    FOR(i, 0, arr.size()) {
    	if(i < lo || i > hi) ans += arr[i]-1;
    }
    ans += best-1;
    cout<<ans;
    return 0;
}