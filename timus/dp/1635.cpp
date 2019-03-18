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

const int N = 4005;
bool pal[N][N];
int dp[N],par[N],n;
string s;
vector<string> vs;

void printOutput(int ind) {
	if(ind <= 0) return;
	int sz = ind-par[ind];
	vs.push_back(s.substr(par[ind], sz));
	printOutput(par[ind]);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(pal, false, sizeof(pal));
    memset(par, 0, sizeof(par));
    cin>>s; n = s.size();

    FOR(i, 0, n+1) {
    	pal[i][i]=true;
    	dp[i]=INT_MAX;
    }
    dp[0]=0;

    FOR(i, 2, n+1) {
    	if(s[i-2]==s[i-1]) {
    		pal[i-1][i]=true;
    	}
    }

    RFOR(i, n-2, 1) {
    	FOR(j, i+1, n+1) {
    		if(s[i-1] == s[j-1] && pal[i+1][j-1]) {
    			pal[i][j]=true;
    		}
    	}
    }

    FOR(i, 1, n+1) {
    	if(pal[1][i]) {
    		dp[i]=1;
    		par[i]=0;
    	} else {
    		RFOR(j, i, 1) {
				if(pal[j][i]) {
					if(dp[i] > dp[j-1]+1) {
						dp[i] = dp[j-1]+1;						
						par[i] = j-1;
					}
				}
    		}
    	}
    }

    cout<<dp[n]<<endl;
    printOutput(n);
    reverse(vs.begin(), vs.end());
    FOR(i, 0, vs.size()) {
    	if (i)
    	{
    		cout<<" ";
    	}
    	cout<<vs[i];
    }

    return 0;
}