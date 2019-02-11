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

const int N = 1e5+5;
ll x[N],y[N];

bool collinear(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (y1-y2)*(x1-x3)==(y1-y3)*(x1-x2) ;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    F(i, 0, n) {
    	cin>>x[i]>>y[i];
    }

    vector<lll> dist(n-1);
    F(i, 1, n) {
    	ll d = (y[i]-y[0])*(y[i]-y[0]) + (x[i]-x[0])*(x[i]-x[0]);
    	dist[i-1] = {d, i};
    }

    sort(dist.begin(), dist.end());
    int ans[3]; ans[0]=0,ans[1]=dist[0].second;
    F(i, 1, dist.size()) {
    	int curr = dist[i].second;
    	if(!collinear(x[0], y[0], x[ans[1]], y[ans[1]], x[curr], y[curr])) {
    		ans[2]=curr;
    		break;
    	}
    }
    F(i, 0, 3) {
    	cout<<ans[i]+1<<" ";
    }

    return 0;
}/*

*/