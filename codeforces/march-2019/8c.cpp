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

const int BMAX = (1 << 24) + 1;
int dp[BMAX], n;
ii handbag, items[25], path[BMAX];

int dist(int i) {
	return (items[i].ff - handbag.ff)*(items[i].ff - handbag.ff) + (items[i].ss - handbag.ss)*(items[i].ss - handbag.ss);
}

int dist2(int i, int j) {
	return (items[i].ff - items[j].ff)*(items[i].ff - items[j].ff) + (items[i].ss - items[j].ss)*(items[i].ss - items[j].ss);	
}

int solve(int mask) {
	if(mask == (1<<n)-1) return 0;
	int &ret = dp[mask];
	if(ret >= 0) return ret;

	ret = INT_MAX;

	FOR(i, 0, n) {
		if(!(mask & (1 << i))) {
			int d1 = dist(i), nextmask = mask | (1 << i);
			int cost1 = 2*d1 + solve(nextmask);
			if(ret > cost1) {
				ret = cost1;
				path[mask].first = i;
				path[mask].second = -1;
			}
			
			FOR(j, 0, n) {
				if(!(nextmask & (1 << j))) {
					int d2 = dist2(j, i);
					int cost2 = d1 + d2 + dist(j) + solve(nextmask | (1 << j));
					if(ret > cost2) {
						ret = cost2;
						path[mask].first = i;
						path[mask].second = j;
					}					
				}
			}
			break;
		}
	}

	return ret;
}

void printPath(int mask) {
	if(mask == (1 << n)-1) return;
	cout<<0<<" "<<path[mask].first+1<<" ";
	if(path[mask].second != -1) {
		cout<<path[mask].second+1<<" ";
		int tmp = mask;
		mask |= (1 << path[tmp].first);
		mask |= (1 << path[tmp].second);
		printPath(mask);
	} else {
		printPath(mask | (1 << path[mask].first));
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    cin>>handbag.ff>>handbag.ss>>n;
    FOR(i, 0, n) {
    	cin>>items[i].ff>>items[i].ss;
    }
    int ans = solve(0);
    cout<<ans<<endl;
    printPath(0); cout<<0;
    return 0;
}