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

int x[1005],n,r;
double y[1005], constant;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    memset(y, 0.0, sizeof(y));
    cin>>n>>r;
    constant = 4.0 * r * r;

    F(i, 0, n) {
    	cin>>x[i];
    	double maxm = r;
    	F(j, 0, i) {
    		double dx = (x[i] - x[j])*(x[i] - x[j]);
    		// deb(dx);
    		if(dx <= constant) {
    			// deb(fmax(y[i], y[j] + sqrt(constant - dx))); 
    			maxm = fmax(maxm, y[j] + sqrt(constant - dx));
    		}
    	}
    	y[i] = maxm;
    }

    cout << fixed << showpoint;
    cout << setprecision(10);
    F(i, 0, n) {
    	cout<<y[i]<<" ";
    }

    return 0;
}/*

*/
