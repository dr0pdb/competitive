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

map<ll,int> freq, curr;
const int MAXN = 10000001; 
  
// stores smallest prime factor for every number 
ll spf[MAXN];
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
  
vector<ll> getFactorization(ll x) 
{ 
    vector<ll> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    }
    return ret; 
}

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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    int n,m,a;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>m;
    	FOR(j, 0, m) {
    		cin>>a;
			vll facts = getFactorization(a);
			for(auto f: facts) {
				curr[f]++;
			}
    	}
    	if(i) {
    		for (auto itr = freq.cbegin(); itr != freq.cend();) {
    			auto itr2 = curr.find(itr -> first); 
				if (itr2 == curr.end()) {
					itr = freq.erase(itr);
				}
				else {
					auto itr3 = freq.find(itr->first);
					itr3->second = min(itr->second, itr2->second);
					++itr;
				}
			}
    	} else {
    		freq = curr;
    	}
    	curr.clear();
    }

    ll val = 1;
    for(auto itr: freq) {
    	val *= power(itr.first, itr.second, MOD);
    	val %= MOD;
    }
    cout<<val;

    return 0;
}