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
const double eps = 1e-9;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
/*----------------------------------------------------------------------*/

int x[105];

double dist(ll xi, ll cx, ll cy) {
	return sqrt((cx - xi)*(cx - xi) + (cy)*(cy));
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,vb,vs,cx,cy;
    cin>>n>>vb>>vs;
    F(i, 0, n) {
    	cin>>x[i];
    }
    cin>>cx>>cy;
    int best=2; double minm = 1e9;
    F(i, 1, n) {
    	double t = x[i]*1.0/vb + dist(x[i], cx, cy)/vs; 
    	if((minm - t)>eps || (fabs(minm- t) < eps && (dist(x[i], cx, cy) < dist(x[best-1], cx, cy)))) {
    		minm = t;
    		best = i+1;
    	}
    	// deb(t);
    }
    cout<<best;

    return 0;
}/*

*/
