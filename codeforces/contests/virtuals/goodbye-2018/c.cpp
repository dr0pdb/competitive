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

vi printDivisors(int n) 
{ 
	vi facts;
    for (int i=2; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
            	facts.push_back(i);     
  
            else {
            	facts.push_back(i);
            	facts.push_back(n/i);
            } 
               
        } 
    } 
    return facts;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    vi divs = printDivisors(n);
    set<ll> ans;
    ans.insert(((ll)n*(n+1LL))/2);

    F(i, 0, divs.size()) {
    	int k = divs[i];

    	// deb(k);
    	ll val = (((ll)n)*(n+2LL-k))/(2LL*k);
    	// deb(val);
    	ans.insert(val);
    }

    ans.insert(1);
    for(auto itr: ans) {
    	cout<<itr<<" ";
    }

    return 0;
}/*

*/