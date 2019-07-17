#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 301;
int mat[N][N], best[N][N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,r,c,k; cin>>t;
    FOR(tn, 1, t+1) {
		cin>>r>>c>>k;
		FOR(i, 0, r) {
			FOR(j, 0, c) {
				cin>>mat[i][j];
			}
		}
		FOR(i, 0, r) {
			FOR(j, 0, c) {
				best[i][j] = 0;
				int minm = mat[i][j], maxm = mat[i][j];
				FOR(p, j, c) {
					minm = min(mat[i][p], minm);
					maxm = max(mat[i][p], maxm);
					if(maxm - minm > k) break;
					best[i][j]++;
				}
			}
		}
		int ans = 0;
		FOR(i, 0, r) {
			FOR(j, 0, c) {
				int curr = best[i][j];
				int ht = curr;
				FOR(p, i+1, r) {
					ht = min(ht, best[p][j]);
					int tmp = ht * (p - i + 1);
					curr = max(curr, tmp);
				}
				ans = max(ans, curr);
			}
		}
    	cout<<"Case #"<<tn<<": "<<ans<<endl;
    }

    return 0;
}