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
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int x,y,z,c[3],a[6];
    cin>>x>>y>>z;

    F(i, 0, 3) cin>>c[i];
    F(i, 0, 6) cin>>a[i];

    int ans = 0;
    if(x > c[0]) {
    	ans += a[5];
    } else if (x < 0) {
    	ans += a[4];
    }

    if(y > c[1]) {
    	ans += a[1];
    } else if(y < 0) {
    	ans += a[0];
    }

    if(z > c[2]) {
    	ans += a[3];
    } else if(z < 0) {
    	ans += a[2];
    }
    cout<<ans;

    return 0;
}/*

*/