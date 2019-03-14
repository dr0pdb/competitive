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

int maxm[3], minm[3];

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,tmp;
    cin>>t;

    F(tn, 1, t+1) {
    	cout<<"Case "<<tn<<": ";
		cin>>n;
		F(i, 0, 3) {
			maxm[i] = INT_MIN;
			minm[i] = INT_MAX;
		}

		F(i, 0, n) {
			F(j, 0, 3) {
				cin>>tmp;
				maxm[j] = max(maxm[j], tmp);
			}
			F(j, 0, 3) {
				cin>>tmp;
				minm[j] = min(minm[j], tmp);
			}
		}

		int ans=1;
		F(j, 0, 3) {
			if(maxm[j] > minm[j]) {
				ans = 0;
				break;
			}

			ans *= (minm[j] - maxm[j]);
		}

		cout<<ans<<endl;
	}

    return 0;
}/*

*/