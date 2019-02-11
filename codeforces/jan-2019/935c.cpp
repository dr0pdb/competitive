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

ll r,x[2],y[2];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>r;
    F(i, 0, 2) {
    	cin>>x[i]>>y[i];
    }

    cout << fixed << showpoint << setprecision(12);
    if(fabs(x[1]-x[0])<eps && fabs(y[1]-y[0])<eps) {
    	cout<<x[0]+r/2.0<<" "<<y[0]<<" "<<r/2.0;
    	return 0;
    }

    ll tmp = (x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]);
    if(tmp >= (r*r)) {
    	cout<<x[0]<<" "<<y[0]<<" "<<r;
    } else {
    	double d = sqrt(tmp);
    	double nr = (d + r)/2.0;
    	double alph = nr - d;
    	double nx = x[0] + ((x[0] - x[1])/d)*alph;
    	double ny = y[0] + ((y[0]-y[1])/d)*alph;
    	cout<<nx<<" "<<ny<<" "<<nr;
    }

    return 0;
}/*

*/
