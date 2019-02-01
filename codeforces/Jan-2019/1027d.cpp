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

const int N = 2e5+5;
int arr[N],c[N],status[N];
ll ans = 0;

void dfs(int curr) {
	status[curr]=2;

	int next = arr[curr];
	if(status[next]==0) {
		dfs(next);
	} else if(status[next] == 2) {
		int tmp = arr[next],minc = c[next];
		while(tmp != next) {
			minc = min(minc, c[tmp]);
			tmp = arr[tmp];
		}
		ans += minc;
	}

	status[curr]=1;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;

    F(i, 0, n) {
    	cin>>c[i];
    }
    F(i, 0, n) {
    	cin>>arr[i]; arr[i]--;
    }
    memset(status, 0, sizeof(status));
    F(i, 0, n) {
    	if(!status[i]) {
    		dfs(i);
    	}
    }
    cout<<ans;

    return 0;
}/*

*/