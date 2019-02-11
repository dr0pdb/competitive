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

const int MAXN = 19;

ll comb[MAXN][MAXN];

void findCoeff(){
	memset(comb, 0, sizeof(comb));
	comb[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
    	comb[i][0] = 1;
    	for (int j = 1; j <= i; j++) {
      		comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);
    	}
	}	
}

//return x^y
ll power(ll x,ll y)
{
    ll res = 1;     
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
 
        y = y>>1; // y = y/2
        x = (x*x);  
    }
    return res;
}

vector<long long> res;

void brute(int pos, int cnt, long long cur){
    if (pos == 18){
        res.push_back(cur);
        return;
    }
    
    brute(pos + 1, cnt, cur * 10);
    
    if (cnt < 3)
        for (int i = 1; i <= 9; ++i)
            brute(pos + 1, cnt + 1, cur * 10 + i);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
	int t;
	cin>>t;

	ll l,r;
	brute(0, 0, 0);
	res.push_back(1000000000000000000);

	while(t--) {
		cin>>l>>r;
		cout<<int(upper_bound(res.begin(), res.end(), r) - lower_bound(res.begin(), res.end(), l))<<endl;
	}
    return 0;
}/*

*/
