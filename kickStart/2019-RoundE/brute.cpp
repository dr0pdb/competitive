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
/*----------------------------------------------------------------------*/

ll cntodd(ll num) {
	ll cnt = 0;
	for(ll i = 1; i <= num; i += 2) {
		if(num % i == 0) cnt++;
	}
	return cnt;
}

ll cnteven(ll num) {
	ll cnt = 0;
	for(ll i = 2; i <= num; i += 2) {
		if(num % i == 0) cnt++;
	}
	return cnt;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FOR(l, 1, 101) {
    	FOR(r, l, l+1) {
    		ll ans = 0;
    		
    		FOR(num, l, r+1) {
    			if(abs(cntodd(num) - cnteven(num)) <= 2) ans++;
    		}

    		cout<<l<<" "<<r<<" "<<ans<<endl;
    		// cout<<l<<" "<<r<<endl;
    	}
    }

    return 0;
}