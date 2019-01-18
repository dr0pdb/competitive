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

const int N = 3005;
lll dp[N][N]; ll arr[N];
bool visited[N][N];
int n;

lll solve(int s, int e, int turn) {
	if(s > e) return {0, 0};
	if(visited[s][e]) return dp[s][e];

	lll ret; lll r1 = solve(s+1, e, 1-turn);
	lll r2 = solve(s, e-1, 1-turn);

	if(turn == 0) {
		r1.first += arr[s];
		r2.first += arr[e];
		lll tmp = r1;
		if(r2.first > tmp.first || (r2.first == tmp.first && r2.second < tmp.second)) tmp = r2;
		ret = tmp; 
	} else {
		r1.second += arr[s];
		r2.second += arr[e];
		lll tmp = r1;
		if(r2.second > tmp.second || (r2.second == tmp.second && r2.first < tmp.first)) tmp = r2;
		ret = tmp;
	}

	visited[s][e]=true;
	return dp[s][e] = ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    F(i, 0, n) {
    	cin>>arr[i];
    }

    memset(visited, false, sizeof(visited));

    lll ans = solve(0, n-1, 0);
    cout<<ans.first-ans.second;

    return 0;
}/*

*/
