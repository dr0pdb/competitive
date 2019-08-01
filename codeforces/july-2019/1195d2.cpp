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

const int N = 1e5+5;
ll arr[N];

//return x^y mod p
ll power(ll x,ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int numberOfDigits(ll n){
    if(n<=9){
        return 1;
    }
    return 1 + numberOfDigits(n/10);
}

int digs[11] = {0};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,p; cin>>n;
    FOR(i, 0, n) cin>>arr[i];
    sort(arr, arr+n);
    ll ans = 0;
    FOR(i, 0, n) {
        int dg = numberOfDigits(arr[i]);
        FOR(curd, 1, 11) {
            if(!digs[curd]) continue;
            ll tmp2 = arr[i]; int cnt = 0; p = 0;
            while(cnt < curd) {
                ll d = tmp2%10; tmp2/=10;
                ll tmp = ((d * power(10LL, p+1, MOD))%MOD + (d * power(10LL, p, MOD))%MOD)%MOD;
                tmp *= digs[curd]; tmp %= MOD;
                ans += tmp; ans %= MOD;
                p += 2;
                cnt++;
            }
            while(tmp2) {
                ll d = tmp2%10; tmp2/=10;
                ll tmp = ((d * power(10LL, p, MOD))%MOD + (d * power(10LL, p, MOD))%MOD)%MOD;
                tmp *= digs[curd]; tmp %= MOD;
                ans += tmp; ans %= MOD;
                p++;
            }
        }
        digs[dg]++;
    	p = 0;
    	while(arr[i]) {
    		ll d = arr[i]%10; arr[i]/=10;
    		ll tmp = ((d * power(10LL, p+1, MOD))%MOD + (d * power(10LL, p, MOD))%MOD)%MOD;
    		tmp *= (n - i); tmp %= MOD;
    		ans += tmp; ans %= MOD;
    		p += 2;
    	}
        // deb(ans);
    }
    cout<<ans;
    return 0;
}