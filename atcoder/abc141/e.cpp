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

map<lll, ii> subs;
int ans = 0, u, v;

void solve(string &s) {
	int n = s.size();

    const int p = 31;
    const int p2 = 71;
    const int m = 1e9 + 9;
    const int m2 = 1e9 + 7;
    vector<long long> p_pow(n), p_pow2(n);
    p_pow[0] = 1; p_pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
        p_pow2[i] = (p_pow2[i-1] * p2) % m2;
    }

    vector<long long> h(n + 1, 0), h2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % m2;
    }

    bool found = false;
    for (int l = n; l >= 1; l--) {
    	if(found) break;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            long long cur_h2 = (h2[i + l] + m2 - h2[i]) % m2;            
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            cur_h2 = (cur_h2 * p_pow2[n-i-1]) % m2;
        	
        	if(subs.find({cur_h, cur_h2}) != subs.end()) {
        		tie(u,v) = subs[{cur_h, cur_h2}];
        		if(v < i + 1) {
        			ans = l;
        			found = true;
        			break;
        		}
        	} else {
        		subs[{cur_h, cur_h2}] = {i + 1, i + l};
        	}
        }
        subs.clear();
    }
}

int main() {
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	int n,u,v,x,y; cin>>n; string s; cin>>s;   
 	solve(s);
 	cout<<ans;
    return 0;
}