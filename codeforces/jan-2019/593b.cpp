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

ll m,b;
vector<lll> v;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    ll n,x[2];
    cin>>n>>x[0]>>x[1];

    F(i, 0, n) {
    	cin>>m>>b;
    	ll y[2];
    	y[0] = m*x[0] + b;
    	y[1] = m*x[1] + b;
    	v.push_back({y[0], y[1]});
    }

    sort(v.begin(), v.end());
    bool ans = false;
    F(i, 1, n) {
    	ans |= (v[i-1].second > v[i].second);

    	if(ans) {
    		break;
    	}
    }

    if(ans) {
    	cout<<"YES";
    } else {
    	cout<<"NO";
    }

    return 0;
}/*

*/
