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

struct vec { ll x, y;
	vec(ll _x, ll _y) : x(_x), y(_y) {} 
};

ll cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    ll x[3],y[3],cr;
    F(i, 0, 3) {
    	cin>>x[i]>>y[i];
    }

    vec ab(x[1]-x[0],y[1]-y[0]), bc(x[2]-x[1], y[2]-y[1]);
    cr = cross(ab, bc);
    if(cr == 0) {
    	cout<<"TOWARDS";
    } else if (cr > 0) {
    	cout<<"LEFT";
    } else {
    	cout<<"RIGHT";
    }

    return 0;
}/*

*/
