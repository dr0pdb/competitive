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
vector<vi> m(105, vi());

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n,a;
    cin>>n;

    int side[205];
    memset(side, -1, sizeof(side));

    F(i, 0, 2*n) {
    	cin>>a;
    	m[a].push_back(i);
    }

    std::sort(m.begin(), m.end(), [](const vector<int> & a, const vector<int> & b){ return a.size() < b.size(); });
    int f = 0, s= 0;
    RF(i, 104, 0) {
    	if(!m[i].size())
    		continue;

    	if(m[i].size() > 1) {
    		f++;
    		s++;
    		side[m[i][0]]=1;
    		side[m[i][1]]=2;
    	} else {
    		if(f > s) {
    			s++;
    			side[m[i][0]]=2;
    		} else {
    			f++;
    			side[m[i][0]]=1;
    		}
    	}
    }
    cout<<s*f<<endl;
    F(i, 0, 2*n) {
    	if(side[i]==-1) {
    		if(f == n) {
    			side[i]=2;
    			s++;
    		} else {
    			side[i]=1;
    			f++;
    		}
		}
		
    	if(i)
    		cout<<" ";
    	cout<<side[i];
    }

    return 0;
}/*

*/
