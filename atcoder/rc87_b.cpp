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

const int N = 8010;
vi d[2];
int x,y;
bool dp[N][2*N]; // dp[i][j], in ith step, reachability of coordinate j+N.
bool frst = false;

bool solve(int turn, int target) {
	target += 8000;
	memset(dp, false, sizeof(dp));
	dp[0][8000]=true;
	int sz = d[turn].size();
	FOR(i, 1, sz+1) {
		int jmp = d[turn][i-1];
		FOR(j, 0, 2*N) {
			if(j - jmp >= 0) {
				dp[i][j] |= dp[i-1][j-jmp];
			}
			// in the first step, the bot is facing +x hence -x is not allowed.
			if(turn == 0 && i == 1 && frst) {
				continue;
			}
			if(j + jmp < 2*N) {
				dp[i][j] |= dp[i-1][j+jmp];
			}
		}
	}
	return dp[sz][target];
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin>>s;
    int turn=0, n = s.size(),cnt=0;
    FOR(i, 0, n) {
    	if(s[i] == 'T') {
    		if(cnt) {
    			d[turn].push_back(cnt);
    			cnt = 0;
			}
    		turn = 1 - turn;
    		continue;
    	}
    	if (i==0) frst = true;
    	cnt++;
    }
    if(cnt) {
    	d[turn].push_back(cnt);
    }
    cin>>x>>y;
    bool poss = solve(0, x) && solve(1, y);
    if(poss) {
    	cout<<"Yes";
    } else {
    	cout<<"No";
    }

    return 0;
}