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

const int N = 1e5+5;
int v,n;
int freq[2][N] = {0}, maxm[2][2], maxi[2][2];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    FOR(i, 0, n) {
    	cin>>v;
    	freq[i%2][v]++;
    }
    memset(maxm, -1, sizeof(maxm));
    memset(maxi, -1, sizeof(maxi));
	FOR(i, 0, 2) {
		FOR(j, 0, N) {
			if(freq[i][j] > maxm[i][0]) {
				maxm[i][1] = maxm[i][0];
				maxi[i][1] = maxi[i][0];
				maxm[i][0] = freq[i][j];
				maxi[i][0] = j;
			} else if(freq[i][j] > maxm[i][1]) {
				maxm[i][1] = freq[i][j];
				maxi[i][1] = j;
			}
		}
	}

	int ans = 2*N;
	if(maxi[0][0] != maxi[1][0]) {
		ans = n - maxm[0][0] - maxm[1][0];
	} else {
		ans = min(n - maxm[0][0] - maxm[1][1], n - maxm[0][1] - maxm[1][0]);
	}
	cout<<ans;

    return 0;
}