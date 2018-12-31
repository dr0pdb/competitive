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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    string s[2];
    cin>>s[0]>>s[1];

    int cnt = 0, n = s[0].size();
    F(i, 1, n) {
    	// int tc = ((s[0][i] == '0') + (s[0][i-1] == '0')), bc = ((s[1][i] == '0') + (s[1][i-1] == '0'));
    	int tc = 0, bc = 0;
    	if(s[0][i] != 'X')
    		tc++;
    	if(s[0][i-1] != 'X')
    		tc++;
    	if(s[1][i] != 'X')
    		bc++;
    	if(s[1][i-1] != 'X')
    		bc++;

    	// cout<<tc<<" and "<<bc<<endl;
    	if(tc + bc >= 3) {
    		cnt++;
    		if(tc == 1 || bc == 1) {
    			// cout<<i<<" in first case\n";
    			s[0][i-1]='X';
    			s[0][i]='X';
    			s[1][i-1]='X';
    			s[1][i]='X';
    		} else {
    			// deb(i);
    			s[0][i-1]='X';
    			s[0][i]='X';
    			s[1][i-1]='X';
    		}
    	}
    }
    // deb(s[0]); deb(s[1]);
    cout<<cnt;

    return 0;
}/*

*/
