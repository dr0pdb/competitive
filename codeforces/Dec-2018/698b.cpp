#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 200005;
int arr[N];
vi roots;
bool visited[N],made[N];
set<ii> removed;
vi g[N];
int changes=0;

void dfs(int curr, int par) {
	visited[curr] = true;
	// deb(curr+1);

	F(i, 0, g[curr].size()) {
		int next = g[curr][i];
		if(removed.find(ii(min(curr,next), max(curr,next))) != removed.end()){
			continue;
		}

		if(!visited[next]) {
			// cout<<"Going from "<<curr+1<<" to "<<next+1<<endl;
			dfs(next, curr);
		} else if(next != par) {
			removed.insert(ii(min(curr,next), max(curr,next)));
			arr[next] = next;
			// cout<<"Setting made of "<<next+1<< "from "<<curr+1<<endl;
			made[next] = true;
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    int n;
    cin>>n;

    F(i, 0, n) {
    	cin>>arr[i]; arr[i]--;
    	if(i == arr[i])
    		continue;
    	g[i].push_back(arr[i]);
    	g[arr[i]].push_back(i);
    }
    memset(made, false, sizeof(made));
    memset(visited, false, sizeof(visited));
    F(i, 0, n) {
    	if(!visited[i])
    		dfs(i, -1);
    }

    int alreadyRoot = 0;
    F(i, 0, n) {
    	if(arr[i] == i) {
    		if(!made[i]) {
    			// deb(i);
    			alreadyRoot = roots.size();
    		}
    		roots.push_back(i);
    	}
    }

    deb(alreadyRoot);
    int sz = roots.size();
	F(i, 0, sz) {
		// deb(roots[i]);
		if(i == alreadyRoot)
			continue;
		arr[roots[i]]=roots[alreadyRoot];
		changes++;
	}
    

    cout<<changes<<endl;
    F(i, 0, n) {
    	if(i)
    		cout<<" ";
    	cout<<arr[i]+1;
    }

    return 0;
}/*

*/
