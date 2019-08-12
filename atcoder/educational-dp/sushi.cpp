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

const int N = 305;
double dp[N][N][N];
int arr[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,cnt1=0,cnt2=0,cnt3=0; cin>>n; 
    FOR(i, 0, n) {
    	cin>>arr[i];
    	if(arr[i] == 1) cnt1++;
    	else if(arr[i] == 2) cnt2++;
    	else cnt3++;
    }
    memset(dp, 0, sizeof(dp));
    FOR(k, 0, N) {
    	FOR(j, 0, N) {
    		FOR(i, 0, N) {
    			if(i + j + k == 0) continue;
    			if(i + j + k >= N) continue;

    			int l = i + j + k;
    			double wait = 1.0 * n / l;
    			double p_a = 1.0 * i / l;
    			double p_b = 1.0 * j / l;
    			double p_c = 1.0 * k / l;

    			if (i)
    			{
    				dp[i][j][k] += p_a * dp[i-1][j][k];
    			}

    			if(j) {
    				dp[i][j][k] += p_b * dp[i+1][j-1][k];
    			}

    			if(k) {
    				dp[i][j][k] += p_c * dp[i][j+1][k-1];
    			}

    			dp[i][j][k] += wait;
    		}
    	}
    }

    coud(dp[cnt1][cnt2][cnt3], 10);
    return 0;
}