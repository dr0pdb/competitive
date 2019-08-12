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

typedef vector<vll> mat;

int n;
mat adj; 

void mult(mat &a, mat b) {
	mat tmp(n, vll(n, 0));
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			FOR(k, 0, n) {
				tmp[i][j] += (a[i][k] * b[k][j]) % MOD;
				tmp[i][j] %= MOD;
			}
		}
	}
	a = tmp;
}

mat exp(mat a, ll kk) {
	mat b(n, vll(n, 0));
	FOR(i, 0, n) b[i][i] = 1LL;
	while(kk) {
		if(kk % 2) {
			mult(b, a);
		}
		mult(a, a);
		kk >>= 1LL;
	}
	return b;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll k; cin>>n>>k;
    adj.resize(n, vll(n, 0));
    mat init(n, vll(n, 0));
    FOR(i, 0, n) {
    	init[i][i]=1;
    	FOR(j, 0, n) {
    		cin>>adj[i][j];
    	}
    }
    adj = exp(adj, k);
    mult(adj, init); ll ans = 0;
    FOR(i, 0, n) {
    	FOR(j, 0, n) {
    		ans += adj[i][j];
    		ans %= MOD;
    	}
    }
    cout<<ans;
    return 0;
}