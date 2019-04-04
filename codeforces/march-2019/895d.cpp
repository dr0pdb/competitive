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

const int N = 1e6+5;
string a,b;
int n;

const int MAXN = N;
ll factorial[MAXN], inverse[MAXN];

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

ll modInverse(ll a, ll m){
    return power(a,m-2,m);
}

void pre() {
    factorial[0] = 1LL; inverse[0] = modInverse(factorial[0], MOD);
    for (int i = 1; i < MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inverse[i] = modInverse(factorial[i], MOD);
    }
}

ll get_ans(int curr, vi &freq) {
	ll ret = factorial[n - 1 - curr];
	FOR(i, 0, freq.size()) {
		if(freq[i] <= 1) continue;
		ret *= inverse[freq[i]];
		ret %= MOD;
	}
	return ret;
}

ll f(string &s, int curr, vi &freq) {
	if(curr == n) return 1;
	ll ret = 0;

	FOR(i, 0, s[curr]-'a') {
		if(freq[i]) {
			freq[i]--;
			ret += get_ans(curr, freq);
			ret %= MOD;
			freq[i]++;
		}
	}

	if(freq[s[curr]-'a']) {
		freq[s[curr]-'a']--;
		ret += f(s, curr+1, freq);
		ret %= MOD;
		freq[s[curr]-'a']++;
	}

	return ret;
}

ll solve(string &s) {
	vi freq(26, 0);
    n = a.size();
    FOR(i, 0, a.size()) {
    	freq[a[i]-'a']++;
    }
	return f(s, 0, freq);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>a>>b;
    pre();
    vi freq(26, 0);
    ll ans = ((solve(b) - solve(a) + MOD) % MOD);
    cout<<ans;

    return 0;
}