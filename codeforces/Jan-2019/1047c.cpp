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

const int MAXN = 15000001; 
  
// stores smallest prime factor for every number 
int spf[MAXN];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
  
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

int n,arr;
map<int, vi> m;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    sieve();
    cin>>n;

    F(i, 0, n) {
    	cin>>arr;
    	vi fac = getFactorization(arr);
    	int prev = -1,cnt=0;
    	F(j, 0, fac.size()) {
    		if(fac[j] == prev) {
    			cnt++;
    		} else {
    			if(cnt) {
    				m[prev].push_back(cnt);	
    			}
    			cnt = 1;
    			prev = fac[j];
    		}
    	}

    	if(cnt) {
    		m[prev].push_back(cnt);
    	}
    }

    int ans = INT_MAX;
    for(auto itr: m) {
    	int sz = itr.second.size();
    	if(sz != n) {
    		ans = min(ans, n-sz);
    	} else {
    		vi tmp = itr.second;
    		sort(tmp.begin(), tmp.end());
    		int cnt = 1;
    		F(i, 1, tmp.size()) {
    			if(tmp[i] != tmp[0]) {
    				break;
    			}
    			cnt++;
    		}
    		ans = min(ans, cnt);
    	}
    }

    if(ans == INT_MAX || ans == n) {
    	ans = -1;
    }
    cout<<ans;
 
    return 0;
}/*

*/
