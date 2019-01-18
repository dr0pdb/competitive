#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,x,y,bx,by;
    cin>>n>>x>>y;

    set<ii> s;
    F(i, 0, n) {
    	cin>>bx>>by;
    	int dx = bx - x, dy = by - y;
    	if(dx < 0) {
    		dx *= -1;
    		dy *= -1;
    	} else if (dx == 0) {
    		dy = abs(dy);
    	}

    	int g = __gcd(dx, abs(dy));
    	if(g) {
    		dx /= g; dy /= g;
    	}

    	s.insert({dx, dy});
    }
    cout<<s.size();

    return 0;
}/*

*/
