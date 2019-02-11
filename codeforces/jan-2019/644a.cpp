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

int col[105][105];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,a,b,cnt=1;
    cin>>n>>a>>b;
	memset(col, 0, sizeof(col));
	F(i, 1, a+1) {
		if(cnt > n) break;
		if(i & 1) {
			F(j, 1, b+1) {
				col[i][j]=cnt++;
				if(cnt > n) {
					break;
				}
			}
		} else {
			RF(j, b, 1) {
				col[i][j]=cnt++;
				if(cnt > n) {
					break;
				}	
			}
		}
	}
	if(cnt != n+1) {
		cout<<-1;
		return 0;
	}

	F(i, 1, a+1) {
		F(j, 1, b+1) {
			cout<<col[i][j]<<" ";
		}
		cout<<endl;
	}

    return 0;
}/*

*/