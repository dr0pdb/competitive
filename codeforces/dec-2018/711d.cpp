#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

int arr[200005];

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

int visited[200005];
vi cycles;
int sz;

void dfs2(int i) {
	visited[i]=3;
	cycles[sz]++;
	if(visited[arr[i]]==3)
		return;

	dfs2(arr[i]);
}

void dfs(int i) {
	visited[i]=2;
	if(visited[arr[i]] == 0) {
		dfs(arr[i]);
	} else if(visited[arr[i]] == 1) {
		visited[i]=1;
		return;
	} else {
		cycles.push_back(0);
		dfs2(i);
		sz++;
	}

	visited[i]=1;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;
    sz = 0;

    F(i, 0, n) {
    	cin>>arr[i];
    	arr[i]--;
    }

    memset(visited, 0, sizeof(visited));
    ll ans = 1, ccnt=0;
    F(i, 0, n) {
    	if(visited[i] == 0) {
    		dfs(i);
    	}
    }

    F(i, 0, sz) {
    	ans *= (power(2, cycles[i], MOD) - 2 + MOD) % MOD;
    	ccnt += cycles[i];
    	ans %= MOD;
    }

    ans *= power(2, n - ccnt, MOD);
    ans %= MOD;
    cout<<ans;

    return 0;
}/*

*/
