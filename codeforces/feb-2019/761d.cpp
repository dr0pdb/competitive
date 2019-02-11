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
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
int a[N],b[N];
ii p[N];

bool cmp(ii a, ii b) {
	return (a.first >= b.first);
}

bool valid(int b, int max_avail, int a) {
	return (b - a < max_avail);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,l,r;
    cin>>n>>l>>r;

    F(i, 0, n) {
    	cin>>a[i];
    }

    F(i, 0, n) {
    	cin>>p[i].first;
    	p[i].second = i;
    }

    sort(p, p+n, cmp);
    
    b[p[0].second] = r;
    int max_avail = r - a[p[0].second];

    F(i, 1, n) {
    	int ind = p[i].second;
		
		int lo = l, hi = r,ans=-1;
		while(lo <= hi) {
			int mid = (lo + hi)/2;
			if(valid(mid, max_avail, a[ind])) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		if(ans == -1) {
			cout<<-1;
			return 0;
		}

		b[ind] = ans;
		max_avail = ans - a[ind];
    }

    F(i, 0, n) {
    	cout<<b[i]<<" ";
    }

    return 0;
}/*

*/