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
const ll MOD = 998244353;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
ll costsame[N],costdiff[N];
int num,n,k;
vi vals[2];

inline ll sq(ll a) {
	return (a * a)%MOD;
}

void pre() {
	costsame[0]=costdiff[0]=1;
	FOR(i, 1, N) {
		if(i & 1) {
			costsame[i] = (sq(costsame[i/2]) + ((k-1)*sq(costdiff[i/2]))%MOD)%MOD;
			costdiff[i] = (2*costsame[i/2]*costdiff[i/2] + ((k-2)*sq(costdiff[i/2]))%MOD)%MOD;
		} else {
			costsame[i] = ((k-1)*costdiff[i-1])%MOD;
			costdiff[i] = (costsame[i-1] + (k-2)*costdiff[i-1])%MOD;
		}
	}
}

ll solve(int idx) {
	ll ret = 0;
	int a=-2,b=-2,cnt=0;
	FOR(i, 0, vals[idx].size()) {
		if(vals[idx][i] == -1) cnt++;
		else {
			if(cnt == 0) {
				a = vals[idx][i];
			} else {
				b = vals[idx][i];
				if(a == -2) {
					ret += ((k - 1LL) * costdiff[cnt - 1] + (costsame[cnt - 1]))%MOD;
				} else {
					if(a == b) {
						ret += costsame[cnt];
					} else {
						ret += costdiff[cnt];
					}
				}

				ret %= MOD;
				cnt = 0;
				a = b; b = -2;
			}
		}
	}

	if(cnt) {
		ret *= ((k - 1LL) * costdiff[cnt - 1] + (costsame[cnt - 1]))%MOD;
		ret %= MOD;
	}

	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>n>>k;
    pre();
    FOR(i, 0, n) {
    	cin>>num;
    	vals[i&1].push_back(num);
    }

    deb(solve(0)); deb(solve(1));
    // ll ans = solve(0) * solve(1) % MOD;
    // cout<<ans;

    return 0;
}